# include <stdio.h>
# include <string.h>
# include <ctype.h>


int main(){
    char str[10000] = "", newstr[10000] = "", upperstr[10000] = "", lowerstr[10000] = "";
    int i, j, len, count = 0, same = 0;
    fgets(str, sizeof(str), stdin);
    
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
    
    printf("%s\n", upperstr);
    printf("%s", lowerstr);
}