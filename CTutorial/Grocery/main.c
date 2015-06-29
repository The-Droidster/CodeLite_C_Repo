//Program to demonstrate the billing process of a grocery shop

//Header Files
#include <stdio.h>
#include <conio.h>

//Functions used
void list();
float rate(int,int);

int main()
{
	int num, ch, count;
	float sum = 0;
	float tax, gtot;
	//clrscr();
	printf("\nWelcome to SEED's grocery store!....\n\n");
    list();         //Display a list of available products for user to select.
    printf("\n\nHow many pruducts would you like to purchase: ");
    scanf("%d", &num);  //count for number of products user wants to purchase
    count = num;    //count retains the value of num provided by user
    printf("\n\t\t\t\t\t\tYour Bill!");
    printf("\n\t\t\t\t=========================================");
    printf("\nSelect products! \t\tSelected Products:\t\tRate. "); //format for bill generation
    printf("\n================\t\t=================\t\t====\n");
    do
    {
        // clrscr();
        // list();
        printf("\nSelect product number %d: ", count - (num - 1)); //Prompt user to select the next product.
        scanf("%d", &ch);
        sum = sum + rate(ch,count - (num - 1)); //total is calculated here. 
												//rate(int, int) returns the price of the current user selected product 
												//which is iteratively added to the current total
												//count - (num - 1) calculates the serial number of the product, 
												//to be displayed in selected product list
        num = num - 1;	//iterate loop 'num' times
    } while(num >= 1);
    
    //Bill generation and calculation of tax and grand total, could be done in a separate module
    printf("\n\t\t\t\t=========================================");
    printf("\n\t\t\t\t\tThe Total is:\t\t%.2f Rs", sum); //Display total
    tax = 0.14 * sum; //Calculate tax 14% on total, taxrate var can be used instead of hardcoding
    gtot = sum + tax; //Calculate grand total
    printf("\n\t\t\t\t\tTax levied:\t\t%.2f  Rs", tax); //Display tax, some formatting for proper display
    printf("\n\n\t\t\t\t\tGrand Total Payable:\t%.2f Rs", gtot); //Display grand total
    printf("\n\n\n\t\tThank You for shopping! Visit Again!");
    getche();
    return 0;
}

float rate(int ch, int ser)  //function to return the price of the product currently selected by user
{	
	//rate takes 2 arguments by value, 
	//1. user choice(ch)
	//2. serial number(ser) of the choice to display a chronological list
	//ser ie. the serial number is calculated and passed in main as count - (num - 1)
	switch(ch)
	{
		case 1:
		printf("\t\t\t\t%d. Product 1.\t\t\t100.00 Rs\n",ser); //ser prints the serial number in Selected products list
		return 100; //return price of product 1 to be added to sum in main

		case 2:
		printf("\t\t\t\t%d. Product 2.\t\t\t200.00 Rs\n",ser);
		return 200; //similarly

		case 3:
		printf("\t\t\t\t%d. Product 3.\t\t\t200.00 Rs\n",ser);
		return 200;

		case 4:
		printf("\t\t\t\t%d. Product 4.\t\t\t250.00 Rs\n",ser);
		return 250;

		case 5:
		printf("\t\t\t\t%d. Product 5.\t\t\t300.00 Rs\n",ser);
		return 300;

		case 6:
		printf("\t\t\t\t%d. Product 6.\t\t\t150.00 Rs\n",ser);
		return 150;

		case 7:
		printf("\t\t\t\t%d. Product 7.\t\t\t400.00 Rs\n",ser);
		return 400;

		case 8:
		printf("\t\t\t\t%d. Product 8.\t\t\t700.00 Rs\n",ser);
		return 700;

		case 9:
		printf("\t\t\t\t%d. Product 9.\t\t\t500.00 Rs\n",ser);
		return 500;

		case 10:
		printf("\t\t\t\t%d. Product 10.\t\t\t300.00 Rs\n",ser);
		return 300;

		default:
		printf("\t\t\t\t%d. Invalid Choice!\t\t\t--.-- Rs\n",ser);
		return 0;
	}
}

void list() //fucntion to display a list of available products

{   
	printf("\nList of products available in stock: \n");
	printf("====================================");
	printf("\nProduct List\t\tPrice");
	printf("\n============\t\t=====");
	printf("\n1. Product 1\t\t100.00 Rs");
	printf("\n2. Product 2\t\t200.00 Rs");
	printf("\n3. Product 3\t\t200.00 Rs");
	printf("\n4. Product 4\t\t250.00 Rs");
	printf("\n5. Product 5\t\t300.00 Rs");
	printf("\n6. Product 6\t\t150.00 Rs");
	printf("\n7. Product 7\t\t400.00 Rs");
	printf("\n8. Product 8\t\t700.00 Rs");
	printf("\n9. Product 9\t\t500.00 Rs");
	printf("\n10. Product 10\t\t300.00 Rs");
}
