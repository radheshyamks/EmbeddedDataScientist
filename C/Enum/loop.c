#include<stdio.h>
int main()
{
    int i=1,sum=0;
    /*for(i=1;i<=100;i++)
    sum=sum+i;
    printf("%d",sum);*/

   /* while(i<=100)
    {
    sum=sum+i;
    i++;
    }
    printf("%d",sum);*/
    do{
        sum=sum+i;
        i++;
    }while(i<=100);
    printf("%d",sum);
    /* Adding 1-100 using for loop*/
    
    /* Adding 1-100 using while loop*/

    /* Adding 1-100 using do-while loop*/
    return 0;
}