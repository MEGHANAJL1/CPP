#include<iostream>
#include<ctype.h>
#include<cmath>
using namespace std;
#define SIZE 20
int stack[SIZE];
int top=-1;
void push(float symbol){
   if(top==SIZE-1){
      cout<<"stack overflow"<<endl;
   }
   else{
    top++;
    stack[top]=symbol;
   }
}
float pop(){
   if(top==-1){
     cout<<"Stack underflow"<<endl;
    }
    else{
    return stack[top--];
    }
}
float operate(char symbol, char op1, char op2){
    switch(symbol){
       case '+' : return op1 + op2;
       case '-' : return op1-op2;
       case '*' : return op1*op2;
       case '/' : return op1/op2;
       case '^' : return pow(op1, op2);
       case '%' : return op1%op2;
      }
}
float evalution(char pos_exp[])
{
    float ans;
    float op1, op2;
    for(int i=0; pos_exp[i]!='\0' ;i++){
        char symbol=pos_exp[i];
       
           if(isdigit(symbol)){
              push(symbol-'0');
           }
           else{
            op2=pop();
            op1=pop();
            ans=operate(symbol,op1,op2);
            push(ans);
            }
        }
        return pop();
}
int main(){
   char pos_exp[SIZE];
   float fans;
   cout<<"Enter te postfix expression"<<endl;
   cin>>pos_exp;
   fans=evalution(pos_exp);
   cout<<"The value of postfix expression is:   "<<endl<<fans;
   return 0;
}