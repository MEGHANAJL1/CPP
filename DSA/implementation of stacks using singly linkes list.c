#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void push(struct Node** top, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));  
    if (new_node == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    new_node->data = data;
    new_node->next = *top;  
    *top = new_node;        
    printf("%d pushed to stack\n", data);
}

int pop(struct Node** top) {
    if (top==NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = *top;  
    *top = (*top)->next;       
    int popped_data = temp->data;
    free(temp);                
    return popped_data;
}
int main() {
    struct Node* stack = NULL;  

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    

    printf("Popped element is %d\n", pop(&stack));  
    printf("Popped element is %d\n", pop(&stack));  
    return 0;
}