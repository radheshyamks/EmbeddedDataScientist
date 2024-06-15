/*#include <stdio.h>
int main()
{
 printf("Hello World\n");
 return 0;
}*/
/*It is bit of tricky to compile a program
  First we have to download MinGW and complete the set up for MinGW
*/
//bubble sort
#include<stdio.h>
void sort(int arr[], int size)
{
	int large = 0;
	for(int i=0; i<size-1; i++)
	{
		for(int j = 0; j < size-i-1; j++)
		{
			if(arr[j]>arr[j+1])
			{
				large = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = large;
			}
		}
	}
}
int main()
{
	void (*fptr)(int [], int) = NULL;
	int arr[] = {9,8,7,6,5,4,3,2,1,0};
	int size = sizeof(arr)/sizeof(arr[0]);
	fptr = sort;
	(*fptr)(arr, size);
	for(int i=0; i<size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}