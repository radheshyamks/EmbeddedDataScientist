#ifndef __HDR__
#define __HDR__
// extern "C"{
#include <stdlib.h>
typedef unsigned int uint_32t;
void insert_data(uint_32t data);
void reverse_list(void);
void print_data(void);
void insert_node_anywhere(uint_32t pos, uint_32t data);
void cleanList(void);
void deleteAnyNode(uint_32t pos);
typedef struct node{
	uint_32t data;
	struct node *prev;
	struct node *next;
}node;
// #define NULL (void*)0
node * start = NULL;
node * end = NULL;
// }
#endif //__cplusplus__