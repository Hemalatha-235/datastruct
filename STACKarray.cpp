#include <stdio.h>
#include <stdlib.h>

#define MAX 5 
int stack[MAX];
int top = -1; 

int isFull() {
    return top == MAX - 1;
}
int isEmpty() {
    return top == -1;
} 

void push(int value) {
   
    if (isFull()) {
        printf("Stack Overflow.\n", value);
        return;
    }
    
    top++;               
    stack[top] = value;  
    printf("%d pushed onto the stack.\n", value);
}
void pop() {
   
    if (isEmpty()) {
        printf("Stack Underflow.\n");
        return;
    }
    
    printf("Popped element: %d\n", stack[top]);
    top--; 
}
void peek() {
    if (isEmpty()) {
        printf("Stack is empty. No top element.\n");
    } else {
        printf("TOP = %d\n", stack[top]);
    }
}
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    
    printf("Stack elements (Top to Bottom):\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
   
}
int main(){
	int choice,value;
	while(1) {
	    printf("\n1. Push\n2. Pop\n3. Peek\n4. Display \n5. Is Empty \n6. Is FUll\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                 pop();
       			 break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                if (isEmpty()) {
                    printf("Status: Stack is  empty.\n");
                } else {
                    printf("Status: Stack is not empty.\n");
                }
                break;
            case 6:
                if (isFull()) {
                    printf("Status: Stack is  full.\n");
                } else {
                    printf("Status: Stack not full.\n");
                }
                break;
            case 7:
                printf("Exiting program.\n");
                exit(0);
            default:
            	printf("Invalid Option");
	}
}
return 0;
}


