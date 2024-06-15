#include <stdio.h>
#include <stdlib.h>
#include "linklist_hdr.h"
node* create_node(void){
    node* p = (node*)malloc(sizeof(node)*1);
    if(p!=NULL){
        p->next = NULL;
        p->prev = NULL;
    }
	return p;
}
void first_node(uint_32t data){
    start=create_node();
	// start->prev=NULL;
	// start->next=NULL;
	start->data = data;
}
void insert_data(uint_32t data){
	if(start == NULL){
		// printf("Starting node has created\n");
        first_node(data);
        return;
	}else{
		node* tmp = start;
		while(tmp->next != NULL){
			tmp = tmp->next;
			// printf("Hello\n");
		}
		node*ptr = create_node();
		ptr->data = data;
        ptr->next = NULL;
        ptr->prev = tmp;
        tmp->next = ptr;
        end = ptr;
	}
	return;
}
void insert_node_anywhere(uint_32t pos, uint_32t data){
    if(pos==0){
        printf("Start position with 1\n");
        return;
    }else{
        if(start==NULL){
            first_node(data);
            return;
        }else{
            if(pos==1){
                node* ptr = create_node();
                ptr->next = start;
                ptr->prev = start->prev;
                ptr->data = data;
                // start->data = data;
                start=ptr;
                return;
            }
            node* tmp=start;
            // uint_32t tmp_pos = 0;
            while(--pos != 0){
                tmp = tmp->next;
                // tmp_pos++;
            }
            if(tmp==NULL){
                insert_data(data);
            }else{
                    // node* next = tmp->next;
                    node* ptr = create_node();
                    ptr->next = tmp;
                    ptr->data = data;
                    ptr->prev = tmp->prev;
                    tmp->prev->next = ptr;
                    tmp->prev = ptr;
            }
        }
    }
    return;
}
void reverse_list(void){
    if(start==NULL){
        printf("list is empty\n");
        return;
    }
    node* tmp = end;
    while(tmp != NULL){
        printf("%d ", tmp->data);
        tmp = tmp->prev;
    }
    printf("\n");
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
void deleteAnyNode(uint_32t pos){
    if(start==NULL){
        printf("List is empty\n");
        return;
    }
    if(pos==1){
        node* tmp=start;
        if(tmp->next==NULL){
            free(start);
            start=NULL;
            return;
        }
        // start = tmp->next;
        tmp->next->prev=tmp->prev;
        start = tmp->next;
        free(tmp);
        return;
    }
    if(pos>1){
        node* tmp=start;
        while(--pos != 0){
            tmp = tmp->next;
        }
        // node* ptr = tmp;
        if(tmp->next==NULL){
            tmp->prev->next=NULL;
            free(tmp);
            return;
        }
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        free(tmp);
        return;
    }
}
void cleanList(void){
    if(start==NULL){
        printf("List is empty\n");
    }else{
        node* tmp=start;
        while(tmp->next!=NULL){
            start = tmp->next;
            start->prev = NULL;
            free(tmp);
            tmp=start;
        }
        if(tmp->next==NULL){
            free(tmp);
        }
        start=NULL;
    }
    return;
}
int main()
{
	uint_32t data=0,pos=0;
	unsigned int x;
	while(1){
		printf("Enter your choice\n");
		printf("1. Add node at end of the list\n");
		printf("2. Print Data\n");
		printf("3. Exit\n");
        printf("4. List in reverse order\n");
        printf("5. Insert the node & data anywhere\n");
        printf("6. Delete first node\n");
        printf("7. Clean list\n");
		scanf("%d",&x);
		switch(x){
			case 1:
                printf("Enter the data: ");
				scanf("%d", &data);
				insert_data(data);
				break;
			case 2:
				print_data();
				break;
			case 3:
				printf("Exiting the program\n");
				exit(0);
            case 4:
                reverse_list();
                break;
            case 5:
                printf("Enter the position: ");
                scanf("%d", &pos);
                printf("\nEnter the data: ");
                scanf("%d", &data);
                insert_node_anywhere(pos,data);
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                deleteAnyNode(pos);
                break;
            case 7:
                cleanList();
                break;
			default:
				printf("Wrong choice\n");
				break;
		}
	}
}