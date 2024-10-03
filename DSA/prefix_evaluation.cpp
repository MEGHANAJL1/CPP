#include<iostream>
#include<ctype.h>
#include<cmath>
#include<cstring>
#define SIZE 20
using namespace std;
struct stack{
    int item[SIZE];
    int top=-1;
}s;
void push(float symbol){
    s.item[++s.top]=symbol;
}
float pop(){
    return s.item[s.top--];
}
float operate(char symbol, float op1,float op2){
    switch(symbol){
        case '+': return op1+op2;
        case '-': return op1-op2;
        case '*': return op1*op2;
        case '/': return op1/op2;
        case '%': return int(op1) % int(op2);
        case '^': return pow(op1,op2);
    }
}
float evaluation(const char* exp){
    float op1,op2,ans;
    int i;
    char symbol;
    int n=strlen(exp);
    for(i=n-1;i>=0;i--){
        symbol=exp[i];
        if(isdigit(symbol)){
            push(symbol-'0');
        }
        else{
            op1=pop();
            op2=pop();
            ans=operate(symbol,op1,op2);
            push(ans);
        }
       
    }
     return pop();
}
int main(){
    float f_ans;
    char exp[SIZE];
    cout<<"Enter the prefix expression "<<endl;
    cin>>exp;
    f_ans = evaluation(exp);
    cout<<"The value of the expression is:"<<endl<<f_ans;
    return 0;

}