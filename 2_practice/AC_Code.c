# include <stdio.h>
# include <string.h>
# include <ctype.h>

int main(){
    char str[10000] = "", pattern[10000] = "";
    fgets(str, sizeof(str), stdin);
    fgets(pattern, sizeof(pattern), stdin);

    int i, j, len, count = 0, same = 0;
    // 找不重複的pattern
    
    char new_pattern[strlen(pattern)];
    for (int i = 0; i < strlen(pattern); i++){
        new_pattern[i] = '\0';
    }
    for (int i = 0; i < strlen(pattern); i++){
        for (int j = 0; j < strlen(new_pattern); j++){
            if (pattern[i] == new_pattern[j] || !isalpha(pattern[i])){
                same = 1;
                break;
            }
        }
        if (same == 0){
            new_pattern[count] = pattern[i];
            count++;
        }
        else{
            same = 0;
        }
    }
    char temp;
    for (int i = 0; i < strlen(new_pattern) - 1; i++) {
        for (int j = i + 1; j < strlen(new_pattern); j++) {
            if (new_pattern[i] > new_pattern[j]) {
                temp = new_pattern[i];
                new_pattern[i] = new_pattern[j];
                new_pattern[j] = temp;
            }
        }
    }

    // 算各個字母總共需要幾個
    int need[strlen(new_pattern)];
    for (i = 0; i < strlen(new_pattern); i++){
        int count = 0;
        for (j = 0; j < strlen(pattern); j++){
            if (new_pattern[i] == pattern[j]){
                count++;
            }
        }
        need[i] = count;
    }

    // 初始化已經有的字母計算陣列
    int have[strlen(new_pattern)];
    for (i = 0; i < strlen(new_pattern); i++){
        have[i] = 0;
    }

    int start = 0, end = 0, min_start, min_end, min_len = 100000;
    for (i = 0; i < strlen(str); i++){
        for (j = 0; j < strlen(new_pattern); j++){
            if (str[i] == new_pattern[j]){
                have[j]++;
                end = i;
                break;
            }
        }
        int have_count = 0;
        for (j = 0; j < strlen(new_pattern); j++){
            if (have[j] >= need[j]){
                have_count++;
            }
        }
        while (have_count == strlen(new_pattern)){
            if (end - start < min_len){
                min_start = start;
                min_end = end;
                min_len = end - start;
            }
            for (j = 0; j < strlen(new_pattern); j++){
                if (str[start] == new_pattern[j]){
                    have[j]--;
                    break;
                }
            }
            start++;
            have_count = 0;
            for (j = 0; j < strlen(new_pattern); j++){
                if (have[j] >= need[j]){
                    have_count++;
                }
            }
        }
    }
    if (min_len == 100000){
        printf("No such window exists");
    }
    else{
        for (i = min_start; i <= min_end; i++){
            printf("%c", str[i]);
        }
    }
    return 0;
}