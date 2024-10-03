#include <iostream>
#include<ctype.h>
#include<cstring>
using namespace std;
#define SIZE 20
struct stack{
    char item[SIZE];
    int top=-1;
}s;
void push(char symbol){
        s.top++;
        s.item[s.top]=symbol;
    
}
char pop(){
        return s.item[s.top--];
}
int precedence(char symbol) {
    switch (symbol) {
        case '^': return 3;
        case '*': return 2;
        case '/': return 2;
        case '%': return 2;
        case '+': return 1;
        case '-': return 1;
        default : return -1;
    }
}
void Infix_To_Prefix(char Infix[]){
    char postfix[SIZE];
    char prefix[SIZE];
    int j=0;
    for(int i=0;Infix[i]!='\0';i++){
        char symbol=Infix[i];
        if(isalnum(symbol)){
            postfix[j++]=symbol;
        }
        else if(symbol=='('){
            push(symbol);
        }
        else if(symbol==')'){
            while(s.item[s.top]!='(' && s.top!=-1){
                postfix[j++]=pop();
            }
            pop();
        }
        else{
            while(precedence(symbol)<=precedence(s.item[s.top]) && s.top!=-1){
                postfix[j++]=pop();
            }
            push(symbol);
            
        }
    }
    while(s.top!=-1){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    int n=strlen(postfix);
    int i;
    for(i=0;i<n;i++){
        prefix[i]=postfix[n-i-1];
        
    }
    prefix[n]='\0';
    cout<<"prefix Expression is    "<<prefix<<endl;
}
int main() {
    int i;
    char infix[SIZE];
    char Infix[SIZE];//reversed infix
    cout<<"Enter the expression"<<endl;
    cin>>infix;
    int n=strlen(infix);
    for(i=0;i<n;i++){
        Infix[i]=infix[n-i-1];
    }
    Infix[i]='\0';
    //reversing the paranthesis
    for(i=0;i<n;i++){
        if(Infix[i]=='('){
            Infix[i]=')';
        }
        else if(Infix[i]==')'){
            Infix[i]='(';
        }
    }
    Infix_To_Prefix(Infix);
    return 0;
}