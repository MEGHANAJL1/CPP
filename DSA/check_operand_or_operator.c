#include<stdio.h>
#include<string.h>
#include<ctype.h>
main(){
    char str[10];
    printf("enter the string");
    scanf("%s",str);
    int i=0;
    while(str[i]!='\0'){
        
        if(isdigit(str[i]) || isalpha(str[i])){
            printf("operend\n");
        }
        else{
            printf("operator\n");
        }
        i++;
    }

}