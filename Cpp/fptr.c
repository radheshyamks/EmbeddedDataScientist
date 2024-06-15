//recursion -> calling the same function again and again
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//#pragma pack(1)
/*static*/ inline int prime(){
	return 100;
}
int main()
{
	struct abc{
		char c;
		int i;
		double d;
	}__attribute__((packed));
	int *k = NULL;
	{
		int x=20;
		k=&x;
		printf("&x = %p\n", &x);
	}
	struct abc a;
	int* ptr1 = (int*)malloc(sizeof(int)*4);
	int* ptr2 = ptr1;
	printf("k = %p , *k = %d, ptr1 = %p,  ptr2 = %p, struct size = %d\n",k, *k, ptr2, ptr1, sizeof(a));// 100, 13
	free(ptr1);
	printf("ptr2 = %p\n", ptr2);// this is illegal access.
	return 0;
}