//Program for user login X number of times

//header files
#include<stdio.h>
#include<conio.h>
#include <unistd.h>

//functions used
int login(int,int);

int main()
{
	int user,pass,loginch;
	int count = 0;
	//clrscr();
	do
	{
		system("cls");
		printf("\nWelcome to login module!\n");
		printf("========================");
		printf("\n\nCaution : You will locked out after 3 unsuccessful login attempts!");
		printf("\n\n===>Login attempts remaining: %d",3-count); //display number of attempts remaining
		printf("\n\nPlease Enter your username and password!\n\n");
		printf("Username: "); //user input
		scanf("%d",&user);
		printf("Password: ");
		scanf("%d",&pass);
		loginch = login(user,pass);//login check, check if login successful
								   //login(user,pass) is called to check if username and password is correct
		if(loginch == 1)
		{	//successful if login returns 1
			printf("\n===>login successful! You got it bitch ;-P! Thank You for using the system!");
			break;
		}
		else
		{	//If login returns 0
			count++; //Increment count, loop progress 
			if(count == 3) //Check if login attempts exceeded, max 3, count will equal 3 after 3rd attempt
			{
				printf("\n===>Still invalid Muthafucka! Max login attempts exceeded! GTFO :-D");
			}
			else
			{	//if attempts are still remaining, continue loop and give user another chance
				printf("\n===>Invalid Username or Password! Please try again!..."); //Print invalid
				printf("\n");
				system("pause");
				continue; //Continue with the loop,allow user another chance
			}
		}
	}
	while(count <= 2); //Allows only 3 chances 0, 1, 2. After this count = 3 and user will not be allowed to try again
					   //loop terminating condition

	getche();
    return 0;
}

int login(int usr, int pwd) //function to check validity of username and password
{	//result returned from here is stored in loginch in main
	if(usr == 123 && pwd == 456) //check
	{
		return 1; //return 1 if username and password are correct
	}
	else
	{
		return 0; //0 otherwise
	}
}
