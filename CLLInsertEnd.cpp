#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
	struct Node *prev; 
};
void display(struct Node *head){
	if (head == NULL) return;
	
	struct Node *temp = head;
    do { 
        printf("%d ", temp->data); 
        temp = temp->next; 
    } while (temp != head); 
    printf("\n");
} 


void InsertAtBeginning(struct Node **head,int value) {
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) return; 
    
    newNode->data = value; 
    
    if(head == NULL) {
    	newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
        return;
	}
struct Node *last = (*head)->prev;
    
    newNode->next = *head;      
    newNode->prev = last;        
    last->next = newNode;       
    (*head)->prev = newNode;
    

   
}

   int main() {
 
 	struct Node *head,*second,*third;
 	
 	head=(struct Node*)malloc(sizeof(struct Node));
 	second=(struct Node*)malloc(sizeof(struct Node));
	third=(struct Node*)malloc(sizeof(struct Node));
	
	head->data = 30;
	second->data = 31;
	third->data = 32;
	
	head->prev = third;
	second->prev = head;
	third->prev = second;
	
	head->next=second;
  	second->next=third;
 	third->next=head;
    display(head);
  
   
   InsertAtBeginning(&head,29);
   display(head);
   
   return 0;
}