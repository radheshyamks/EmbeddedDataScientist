#include <stdio.h>
// gcc hi.c -D=MACRO_DEF
// gcc hi.c
#ifdef MACRO_DEF
#error "Error message"
#endif // end if 
int main()
{
 printf("hi\n");
 return 0;
}