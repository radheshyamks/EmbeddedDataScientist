// write a program to #evaluate this person is eligigble to vote or not;
#include<stdio.h>
int main()
{
    int age=12;
    scanf(" %d", &age);
    if(age>=18 && age<=125)
    printf("valid age to vote");
    else
    printf("not valid age");
        if(age<16)
        printf("\nthis is child");
        else if(age==16 || age==17)
        printf("\nthis is teneger");
        else
        printf("\nthis is adult");        
}
