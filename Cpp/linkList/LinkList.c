#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}Node;
Node *start = NULL;
Node* create_node()
{
	Node* temp = (Node*)malloc(sizeof(Node));
	return temp;
}
void insert_data(){
	Node* temp, *p;
	temp = create_node();
	temp->next = NULL;
	printf("Enter Data: ");
	scanf("%d",&temp->data);
	if(start == NULL){
	 start = temp;
	}else{
		p = start;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = temp;
	}
}
void print(){
	Node * temp;
	if(start == NULL){
		printf("List is Empty\n");
	}else{
		temp = start;
		while(temp != NULL){
			printf("%d ",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}
int main()
{
	int x;
	while(1){
		printf("Enter your choice\n");
		printf("1. Enter the data\n");
		printf("2. Print data\n");
		printf("3. Exit\n");
		scanf("%d",&x);
		switch(x){
			case 1:
					insert_data();
					break;
			case 2:
					print();
					break;
			case 3:
					exit(0);
			default:
					printf("Wrong choice\n");
		}
	}
	return 0;
}