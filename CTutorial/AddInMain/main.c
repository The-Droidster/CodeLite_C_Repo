//program to add two numbers, all logic(addition logic) in main

//Header Files
#include<stdio.h>
#include<conio.h>

int main()
{
	int a,b,c;
	//clrscr();
	printf("Enter the first number: "); //User input
	scanf("%d",&a);
	printf("Enter the second number: ");
	scanf("%d",&b);
	c = a + b; //Calculate sum
	printf("The result of addition is: %d",c); //Display sum
	getche();
    return 0;
}