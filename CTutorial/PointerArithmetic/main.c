//pre-processor directives,header files

#include <stdio.h>
#include <conio.h>

//functions used, prototypes

void calculate(int,int,int);
int add(int*,int*);
int sub(int*,int*);
int mul(int*,int*);
float div(int*,int*);

int main()
{
	int a,b,ch;
	//clrscr();
//user input	
	printf("\nPointer Arithmetic on 2 numbers:\n");
	printf("===============================");
	printf("\n\nEnter first number: ");
	scanf("%d",&a);
	printf("\nEnter second number: ");
	scanf("%d",&b);
//choice of operation.
	printf("\n\n1. Press 1 for Addition.");
	printf("\n2. Press 2 for Substraction.");
	printf("\n3. Press 3 for Multiplication.");
	printf("\n4. Press 4 for Division.\n\nChoice?: ");
	scanf("%d",&ch);
	calculate(ch,a,b);
	getche();
    return 0;
}

void calculate(int ch, int a, int b) //a,b are passed by value, calculate() works on copies, original parameters of main() untouched
{
	int resadd,ressub,resmul;
	float resdiv; //for decimal output, note the return type of div(float)
	switch(ch)	//Do operation based on user choice
	{
		case 1 : resadd = add(&a,&b); //arguments passed by ref, addresses of variables passed, actual parameters(local copies) of calculate() altered
		printf("\nThe result of addition is: %d",resadd);
		break;

		case 2 : ressub = sub(&a,&b); //arguments passed by ref
		printf("\nThe result of substraction is: %d",ressub);
		break;

		case 3 : resmul = mul(&a,&b); //arguments passed by ref
		printf("\nThe result of multiplication is: %d",resmul);
		break;

		case 4 : resdiv = div(&a,&b); //arguments passed by ref
		printf("\nThe result of division is: %.2f",resdiv);
		break;

		default : printf("\nInvalid choice!");
	}
}

//function definition
int add(int*a, int*b) //pass by ref, original paramters altered,pointers of type integer
{
	return *a + *b; //'*' accesses value
}

int sub(int*a, int*b) //pass by ref
{
	return *a - *b;
}

int mul(int*a, int*b) //pass by ref
{
	return (*a)*(*b);
}

float div(int*a, int*b) //pass by ref
{
	return (*a)/(float)(*b); //Either num'ter or den'ter should be typecasted to float
}