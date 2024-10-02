#include<stdio.h>
void TowerHanoi(int n,char S,char D,char T){
    if(n==1){
        printf("\n move %d disc from %c to %c",n,S,D);
    }
    else{
          TowerHanoi( n-1,S,T,D);
          printf("\n move %d disc from %c to %c",n,S,D);
          TowerHanoi( n-1,T,D,S);
         
          
    }
}
int main(){
    int n;
    char S='s';
    char D='d';
    char T='t';
    scanf("%d",&n);
    TowerHanoi(n,S,D,T);
    return 0;
}