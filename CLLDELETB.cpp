#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
	struct Node *prev; 
};
struct Node *head = NULL; 

void display(struct Node *head){
	if (head == NULL) return;
	
	struct Node *temp = head;
    do { 
        printf("%d ", temp->data); 
        temp = temp->next; 
    } while (temp != head); 
    printf("\n");
} 


void deleteBeginning() {
     if (head == NULL) {
         printf("empty");
         return;
     }
	if (head->next == head) {
		free(head);
		head = NULL;
		return;
	}
	
    struct Node *last = head->prev;
	struct Node *temp = head;
	
	head = head->next;
	head->prev = last;
	last->next = head;
} 
int main() {
 
 	struct Node *second,*third;
 	
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
    
   deleteBeginning();
   display(head);
   return 0;
}