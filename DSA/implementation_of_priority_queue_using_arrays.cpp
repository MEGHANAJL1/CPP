#include <iostream>
#define SIZE 10
using namespace std;
struct QUEUE{
    int front=-1;
    int rear=-1;
    int data[SIZE];
}q;

// insertion
void enqueue(QUEUE *q, int item){
    int pos;
    if(q->rear==SIZE-1){
        cout<<"\n queue is full"<<endl;
    }
    else{
        pos=q->rear;
        q->rear=q->rear+1;
        while(pos>=0 && q->data[pos]>=item){
            q->data[pos+1]=q->data[pos];
            pos=pos-1;
        }
        q->data[pos+1]=item;
        if(q->front==-1){
            q->front=q->front +1;
        }
            
        
    }
}

//deletion
int dequeue(QUEUE *q){
    if(q->rear==-1 && q->front==-1){
        cout<<"\n queue is empty"<<endl;
        return -1;
    }
    else{
        cout<<"the highest priorty element is"<< q->data[q->front]<<"is deleted sucessfully"<<endl;
        q->rear--;
    }
    return 0;
}
void display(QUEUE *q){
    cout<<"the elements of the queue are"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<q->data[i]<<endl;
    }
}


int main() {
    while(1){
        int c;
        int num;
    cout<<"1. Insert an element \n  2.Delete an element \n 3.Display the queue \n 4.exit \n"<<endl;
    
    cout<<"enter your choice "<<endl;
    cin>>c;
    
        if(c==1){
            cout<<"enter the element to be added"<<endl;
            cin>>num;
            enqueue(&q,num);
        }
        else if(c==2){
            dequeue(&q);
        }
        else if(c==3){
            display(&q);
        }
        else{
            break;
        }
    }
    
    return 0;

    
}