#include<stdio.h>
#include<stdlib.h>
 struct Node {
    int data;
    struct Node* next;
};
struct Node *top=NULL;

void push(int value);
int pop();
int peek();
int isEmpty();
int isfull();
void display();
 
void push(int value){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	 if (newNode == NULL) {
        printf("Stack Overflow.\n", value);
        return;
    }
  newNode->data = value;
  newNode->next = top;
  top = newNode;
  printf("Pushed %d succesfully",value);

} 

int isEmpty() {
    return top == NULL;
}
int isFull() {
    return top == top - 1;
}

int pop() {
   
    if (isEmpty()) {
        printf("The stack is empty\n");
        return -1; 
    } 
    struct Node* temp = top;   
    int popped = top->data; 
    top = top->next;           
    free(temp);                
    
    return popped;
}
int peek() {
   
    if (isEmpty()) {
        printf("The stack is empty\n");
        return -1; 
    } 
    return top->data;
}
void display() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return;
    }
    
    struct Node* temp = top;
    printf("Stack elements\n");
    while (temp != NULL) {
        printf(" %d \n", temp->data);
        temp = temp->next;
    }
}
int main(){
	int choice,value;
	while(1) {
	    printf("\n1. Push\n2. Pop\n3. Peek\n4. Display \n5. Is empty \n6. Is FUll\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("Popped: %d\n", value);
                }
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("Top element: %d\n", value);
                }
                break;
            case 4:
                display();
                break;
                case 5:
                if (isEmpty()) {
                    printf("Status: Stack is empty.\n");
                } else {
                    printf("Status: Stack is not empty\n");
                }
                break;
            case 6:
                if (isFull()) {
                    printf("Status: Stack is completely full.\n");
                } else {
                    printf("Status: Stack is not full .\n");
                }
                break;
            case 7:
                printf("Exiting program.\n");
                exit(0);
            default:
            	printf("Invalid Option");
           
	}
}
}
	
	




 