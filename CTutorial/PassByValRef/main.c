//program to demonstrate the use of pass by value and pass by reference for parameter passing.
//program output is self-explanatory! Explains itself while producing the output :p

//header files

#include <stdio.h>
#include <conio.h>
#include <unistd.h>

//fucntion prototypes
void addv(int,int,int); //add using pass by Value
void addr(int*,int*,int*); //add using pass by Reference

int main()
{
	int a,b,res,ch;
	res = 0;
	//clrscr();
	printf("\nPress any key to step through during execution!..");
	printf("\n\nValue of res in main() before any processing: %d",res);
	getche();
	printf("\n\nEnter first number: ");
	scanf("%d",&a);
	printf("Enter second number: ");
	scanf("%d",&b);
	printf("\n\n1. Press 1 for Addition using pass by value.");
	printf("\n\n2. Press 2 for Addition using pass by reference.\n\nChoice?: ");
	scanf("%d",&ch);
	system("cls");
	switch(ch)
	{
		case 1 :
		{
			printf("\n\nAddition using pass by value!\n");
			printf("============================");
			getche();
			printf("\n\nPassing your input as value to add function...");
			addv(a,b,res); 		//call by value
			printf("\n\nBack in main!\n");
			getche();
			printf("\nValue of res in main(): %d\t(Unchanged)",res);//retains value of res in main
			getche();
			printf("\n\nConclusion: Pass by value operates on local copies of variables \nand hence does not change the actual variables in main().");
			break;
		}

		case 2 :
		{
			printf("\n\nAddition using pass by reference!\n");
			printf("================================");
			getche();
			printf("\n\nPassing your input as a reference to add function...");
			addr(&a,&b,&res);		//call by reference
			printf("\n\nBack in main!\n");
			getche();
			printf("\nValue of res in main(): %d\t(Changed)",res);//changes the value of res in main
			getche();
			printf("\n\nConclusion: Pass by ref operates directly on the addresses of the \npassed variable and hence actual/original variables in main() are changed.");
			break;
		}

	}
	getche();
	return 0;
}

void addv(int a, int b, int res) //pass by Value, works on local copies inside the function
{
	getche();
	printf("\n\nInside add() function\n");
	getche();
	printf("\nCreated local copies of your arguments.\nOriginal value in main() shall remain unchanged.");
	res = a + b;
	getche();
	printf("\n\nCalculated value of res in add function: %d",res);
	getche();
	printf("\n\nReturning to main()...");
	getche();
}

void addr(int*a, int*b, int*res) //pass by Reference, works on actual parameter(addresses), 
//copies the address of the argument being passed into the formal parameters
{
	getche();
	printf("\n\nInside add() function\n");
	getche();
	printf("\nOperating directly on addresses of arguments.\nOriginal value in main() shall change.");
	*res = *a + *b;
	getche();
	printf("\n\nCalculated value of res in add function: %d",*res);
	getche();
	printf("\n\nReturning to main()...");
	getche();
}