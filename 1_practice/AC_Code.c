#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
//65-90 A~Z 97-122a~z
int main()
{
    char str[100001];
    gets(str);
    int len = strlen(str);
    int lowercase[26] = {0};//小寫字母a~z的出現次數
    int uppercase[26] = {0};//Ａ～Ｚ

    
    for(int i = 0 ; i < len ; i++)
    {
        if(islower(str[i]))//小寫 計算小寫次數
        {
            int x = str[i];//A~Z65-90 uppercase[0]-25
            lowercase[x-97]++;
            
        }
        else if (isupper(str[i]))
        {
            int y = str[i];//A~Z65-90 uppercase[0]-25
            uppercase[y-65]++;    
        }
    }
    bool nolowercase = 1, nouppercase =1;
    for( int i = 0 ; i < 26 ; i++)
    {
        if (lowercase[i] !=0)//出現小寫字母 
        {
            nolowercase =0 ;
            break;
        }
    }
    for( int i = 0 ; i < 26 ; i++)
    {
        if (uppercase[i] !=0)
        {
            nouppercase = 0;
            break;
        }
    }
    if(nouppercase )
    printf("None");
    else{
    for(int i = 0 ; i < 26 ; i++)
    {
        if(uppercase[i] != 0)
        printf("%c" , i+65);
    }
    }
    printf("\n");
    
    if(nolowercase )
    printf("None");
    else{
    for(int i = 0 ; i < 26 ; i++)
    {
        if(lowercase[i] != 0)
        printf("%c" , i+97);
    }
    }
    return 0;
}