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
void insertAtEnd(struct Node **head,int value ){

    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next =NULL;
    
    struct Node *temp = *head;
    
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp; 

    printf("after insertion:\n");
    display(*head);
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
 insertAtEnd(&head,33);
 return 0;
 
}