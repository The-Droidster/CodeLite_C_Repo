//Program to demonstrate pointer declaration, initialisation and access.

//header files
#include <stdio.h>
#include <conio.h>

int main()
{
	int a = 100; //var a initialised to 100.
	int*b = &a; //b is a pointer that holds the address of a.
	int**c = &b; //c is a double pointer that holds the address of b
		     // which in turn holds the address of a
	//clrscr();
	printf("1. Value of a accessed through a(a): %d",a);
	printf("\n\n2. Value of a/value pointed to by b accessed through b(*b): %d",*b);
	printf("\n\n3. Address of a accessed through a(&a): %u",&a);
	printf("\n\n4. Address of a/value of b accessed through b(b): %u",b);
	printf("\n\n5. Address of b accessed through b(&b): %u",&b);
	printf("\n\n6. Address of b/value of c accessed through c(c): %u",c);
	printf("\n\n7. Value of b(which holds address of a) accessed through c(*c): %u",*c);
	printf("\n\n8. Value of a accessed through c(*(*c)): %d",*(*c));
	printf("\n\n9. Address of c accessed through c(&c): %u",&c);
	getche();
    return 0;
}