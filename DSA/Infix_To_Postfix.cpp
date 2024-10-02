#include <iostream>
#include<ctype.h>
#define SIZE 20
using namespace std;
char stack[SIZE];
int top=-1;

void push(char symbol){
    if(top==SIZE-1){
        cout<<"stack overflow"<<endl;
    }
    else{
        top++;
        stack[top]=symbol;
    }
}
char pop(){
    if(top==-1){
        cout<<"stack underflow"<<endl;
        return '\0';
    }
    else{
        char s=stack[top];
        top--;
        return s;
    }
}
int precedence(char symbol){
    switch(symbol){
        case '^':return 3;
        case '*': return 2;
        case '%': return 2;
        case '/': return 2;
        case '+': return 1;
        case '-':return 1;
        default: return -1;
    }
}
void Infix_To_Postfix(char infix[]){
    char postfix[SIZE];
    int j=0;
    for(int i=0;infix[i]!='\0';i++){
        char symbol=infix[i];
        if(isalnum(symbol)){
            postfix[j++]=symbol;
        }
        else if(symbol=='('){
            push(symbol);
        }
        else if(symbol==')'){
            while(stack[top]!='(' && top!=-1){
                postfix[j++]=pop();
            }
            pop();
        }
        else{
            while(precedence(symbol)<=precedence(stack[top]) && top!=-1){
                postfix[j++]=pop();
            }
            push(symbol);
            
        }
    }
    while(top!=-1){
        postfix[j++]=pop();
    }
    postfix[j]=='\0';
    cout<<"the postfix expression is   "<<postfix<<endl;
}
int main() {
    char infix[SIZE];
    cout<<"Enter the infix expression"<<endl;
    cin>>infix;
    Infix_To_Postfix(infix);
    return 0;
    
}