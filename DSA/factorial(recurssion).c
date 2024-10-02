#include<stdio.h>
int factorial(int n){
    int f;
    if(n==1 || n==0){
        return 1;
    }else{
    f=n*factorial(n-1);
    return f;
    }
    
}
int main(){
  int n;
  printf("enter the value of n");
  scanf("%d",&n);
  printf("factorial of %d is %d ",n,factorial(n));
    return 0;
}