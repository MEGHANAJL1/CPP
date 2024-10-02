#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#define size 100
struct Stack {
    int top;
    float exp[size];
};
void evalution(struct Stack *s, char exp){

    char ope1,ope2,res;float sym;
    for( int i=0;exp[i]!='\0';i++){
        if(isdigit(exp[i])){
            push(s, exp[i]-98);
        }
        else if(isalpha(exp[i])){
            printf("enter the value");
            scanf("%f",&sym);
            push(s,sym);
            
        }
        else{
            ope2=pop(s);
            ope1=pop(s);
            res=operate(ope1,ope2,exp[i]);
            push(s,res);
            
        }
    }
    return res;
}
void push(struct Stack *s,float item){
    s->top++;
    s->exp[s->top]=item;
}
float pop(struct Stack *s){
    return s->exp[s->top];
    s->top--;
}
float operate(float ope1,float ope2,char sym){
    switch(sym){
        case '+': return ope1+ope2;break;
        case '-': return ope1-ope2;break;
        case '*': return ope1*ope2;break;
        case '/': return ope1/ope2;break;
        
        case '^': return pow(ope1,ope2);break;
    }
}
int main(){
    char exp[20];
    struct Stack s;
    s.top=-1;
    printf("enter the expression");
    scanf("%s",exp);
    res=evalution(&s,exp);
    printf("result=%f",&res);
    return 0;
}