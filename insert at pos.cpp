#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
void display(struct Node *head){
	struct Node *temp=head;
	while(temp!=NULL){
	printf("%d ", temp->data);
	temp=temp->next;
}
}
 void insertAtPos(struct Node **head,int value,int pos){

 
 
 struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
 newNode->data=value;
 struct Node *temp = *head;
 for (int i=1;i<pos-1&& temp!=NULL;i++)
 	temp=temp->next;
 	if (temp == NULL) {
        printf("Position  is out of range.\n");
        return;
}
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
 head->next=second;
 second->next=third;
 third->next=NULL;
 display(head);
 insertAtPos(&head,29,2);
 return 0;
}