#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
char* findsubstri(char *str,char *pattern){
//此function為求出在str中包含pattern的最短子字串
   

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
    static  char substr[10001];//函數要反還的字串,加上static,不然return會出問題
    if (min_len == 100000){
        printf("No such window exists");
    }
    else{
        strncpy(substr , str+min_start , min_end - min_start +1 );//將最短子字串複製到substr
    }
    substr[min_end - min_start +1] ='\0';
    return substr;
}

char* find_unique_letter(char *str){
    char newstr[10000] = "";
    static char upperstr[10000] = "", lowerstr[10000] = "";
    int i, j, len, count = 0, same = 0;
    
    for (int i = 0; i < strlen(str); i++){
        for (int j = 0; j < strlen(newstr); j++){
            if (str[i] == newstr[j] || !isalpha(str[i])){
                same = 1;
                break;
            }
        }
        if (same == 0){
            newstr[count] = str[i];
            count++;
        }
        else{
            same = 0;
        }
    }
    
    int count_upper = 0, count_lower = 0;
    for (int i = 0; i < strlen(newstr); i++){
        if (isupper(newstr[i])){
            upperstr[count_upper] = newstr[i];
            count_upper++;
        }
        else if (islower(newstr[i])){
            lowerstr[count_lower] = newstr[i];
            count_lower++;
        }
    }

    char temp;
    for (int i = 0; i < strlen(upperstr) - 1; i++) {
        for (int j = i + 1; j < strlen(upperstr); j++) {
            if (upperstr[i] > upperstr[j]) {
                temp = upperstr[i];
                upperstr[i] = upperstr[j];
                upperstr[j] = temp;
            }
        }
    }
    for (int i = 0; i < strlen(lowerstr) - 1; i++) {
        for (int j = i + 1; j < strlen(lowerstr); j++) {
            if (lowerstr[i] > lowerstr[j]) {
                temp = lowerstr[i];
                lowerstr[i] = lowerstr[j];
                lowerstr[j] = temp;
            }
        }
    }
    static char unique[20000] = "";
    int count_unique = 0;
    for (int i = 0; i < strlen(upperstr); i++){
        unique[count_unique] = upperstr[i];
        count_unique++;
    }
    for (int i = 0; i < strlen(lowerstr); i++){
        unique[count_unique] = lowerstr[i];
        count_unique++;
    }
    
    return unique;
}

int main()
{
    char str[10001], unique[10001] = "", substring[10001] = "";
    fgets(str,10001,stdin);
    int str_times[strlen(find_unique_letter(str))];
    for (int i = 0; i < strlen(find_unique_letter(str)); i++){
        str_times[i] = 0;
    }
    strcpy(unique, find_unique_letter(str));
    strcpy(substring, findsubstri(str, unique));
    for (int i = 0; i < strlen(unique); i++){
        for (int j = 0; j < strlen(substring); j++){
            if (unique[i] == substring[j]){
                str_times[i]++;
            }
        }
    }
    printf("%s\n",substring);
    for (int i = 0; i < strlen(unique); i++){
        printf("%d ", str_times[i]);
    }
    return 0;
}
