#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
  void display(struct Node *head){
	struct Node *temp=head;
	while(temp!=NULL){
	printf("%d ", temp->data);
	temp=temp->next; 
}
}
void insertAtFront(struct Node **head,int value ){

    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = *head;
    
	printf("\nafter insertion at beginning:\n");
    display(newNode);
}
int main() {
 
 struct Node *head,*second,*third;
 head=(struct Node*)malloc(sizeof(struct Node));
 second=(struct Node*)malloc(sizeof(struct Node));
 third=(struct Node*)malloc(sizeof(struct Node));
 head->data = 30;
 second->data = 31;
 third->data = 32;
 head->prev = NULL;
 second->prev = head;
 third->prev = second;
 head->next=second;
 second->next=third;
 third->next=NULL;
 
 display(head);
 insertAtFront(&head,29);
 
 return 0;
 
}