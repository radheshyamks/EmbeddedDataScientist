#include<stdio.h>
void fun(int *);
int main()
{
    int i;
    printf("The value of i = ");
    scanf("%d",&i);
    //printf("\n");
//int v = fun(i);
fun(&i);
//printf("The final value of i = %d", v);
printf("The final value of i = %d",i);
}

/*int fun(int i)
{
    i++;
    return i;
}*/

void fun(int *ptr)
{
    (*ptr)++;
}
