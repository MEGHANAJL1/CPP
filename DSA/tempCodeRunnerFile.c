#include<stdio.h>
#define size 10
int Queue[size];
int front,rear,num,c;
void insert(int num){
    if(rear==size-1){
        printf("Queue is overflow");
        return;
    }
    if(front==-1 && rear==-1){
        front=rear=0;
    }
    else{
        rear++;
    }
    Queue[rear]=num;
}
void deletion(){
    if(rear==-1 && front==-1){
        printf("Queue is underflow");
    }
    else{
        printf("the deleting element is %d \n",Queue[rear]);
        rear--;
    }
}
void display(){
    printf("The elements of the queue are");
    for(int i=0; i<size ;i++){
        printf("%d     ",Queue[i] );
    }
}
int main(){
    while(1){
    printf("1. Insert an element \n  2.Delete an element \n 3.Display the queue \n 4.exit \n");
    
    printf("enter your choice ");
    scanf(" %d", &c);
    
        if(c==1){
            printf("enter the element to be added");
            scanf("%d", &num);
            insert(num);
        }
        else if(c==2){
            deletion();
        }
        else if(c==3){
            display();
        }
        else{
            break;
        }
    }
    
    return 0;
}