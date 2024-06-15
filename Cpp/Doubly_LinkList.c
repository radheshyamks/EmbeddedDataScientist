#include <stdio.h>
#include <stdlib.h>
typedef unsigned int uint_32t;
void insert_data(uint_32t data);
void print_data(void);
typedef struct node{
	uint_32t data;
	struct node *prev;
	struct node *next;
}node;
node * start = NULL;
node* create_node(void){
	return (node*)malloc(sizeof(node)*1);
}
void insert_data(uint_32t data){
	if(start == NULL){
		start=create_node();
		start->prev=NULL;
		start->next=NULL;
		start->data = data;
		printf("Starting node has created\n");
	}else{
		node* tmp = start;
		while(tmp->next != NULL){
			tmp = tmp->next;
			printf("Hello\n");
		}
		tmp->next = create_node();
		tmp->data = data;
	}
	return;
}
void print_data(){
	if(start == NULL){
		printf("List is empty\n");
		return;
	}else{
		node* tmp = start;
		while(tmp != NULL){
			printf("%d ", tmp->data);
			tmp = tmp->next;
		}
		printf("\n");
	}
	return;
}
int main()
{
	uint_32t data;
	unsigned int x;
	while(1){
		printf("Enter your choice\n");
		printf("1. Enter Data\n");
		printf("2. Print Data\n");
		printf("3. Exit\n");
		scanf("%d",&x);
		switch(x){
			case 1:
				scanf("%d", &data);
				insert_data(data);
				break;
			case 2:
				print_data();
				break;
			case 3:
				printf("Exiting the program\n");
				exit(0);
			default:
				printf("Wrong choice\n");
				break;
		}
	}
}