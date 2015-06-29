//Program to add two numbers, addition logic in separate add function

//Header Files
#include<stdio.h>
#include<conio.h>

int add(int, int); //function prototype

//sleep causes pause for demonstration purpose
int add(int a, int b)  //function definition
{	
	//Add function body,performs addition and returns the result to main

	sleep(2);  //pause to demonstrate the working
	printf("\nInside add...\n");
	sleep(2);
	printf("calculating sum\n");
	sleep(2);
	printf("Returning to main()...\n");
	return a+b; //add and return the result
}

int main()
{
	int a,b,res;
	//clrscr();
	printf("\nInside main()\n");
	sleep(1);
	printf("Enter the first number: "); //get user input
	scanf("%d",&a);
	printf("Enter the second number: ");
	scanf("%d",&b);
	sleep(1);
	printf("\nCalling add()\n");
	res = add(a,b); //function call with pass by value
	sleep(2);
	printf("\nBack in main()\n");
	sleep(2);
	printf("The result of addition is: %d",res); //display result of addition performed by add function

	getche();
    return 0;
}