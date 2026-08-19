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
    
	*head= newNode; 
   
}
   void insertPosition(struct Node **head,int value, int pos) {
   if (pos == 1) {
      InsertAtBeginning(head, value);
	return;
	}
	struct Node *temp = *head;
	for (int i = 1; i< pos - 1; i++) {
	temp = temp->next;
	}
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;		
	newNode->next = temp->next;
	newNode->prev = temp;
	temp->next->prev = newNode;
	temp->next = newNode;
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
 	insertPosition(&head,24,2);
   display(head);
   
   return 0;
}