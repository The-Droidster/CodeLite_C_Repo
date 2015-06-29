//Program to demonstrate a railway booking system
//Header Files
#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <string.h>

//functions used
int login(char[], char[]);
int booking(int, int);
int bookmenu(int, int, int);
int logincheck(int);
void createuser();

int main(void)
{
    char user[10], pass[10];
    int logres, seats, bookres, bookch, loginch, usercheck;
    int maxseats = 20; //hardcoded max seats available
    system("cls");
    printf("\nWelcome to Railway booking system!\n");
	//Provide option to login or sign up
    printf("1. Press 1 to Login if you have already signed up.\n");
    printf("2. Press 2 to Sign Up.\n\n");
    printf("Your Choice?: ");
    scanf("%d", &loginch);
    usercheck = logincheck(loginch); //Check if user opted for login or sign-up
    if(usercheck == 1) //user opted for login in loginch, logincheck() returns 1
    {
    A:	//label to return to login after sign-up
        printf("\nUser Login:\nPlease enter your username and password:\n");
        printf("Username: ");
        scanf("%s", user);
        printf("Password: ");
        scanf("%s", pass);
        logres = login(user, pass); //call to login, checks if user name and pass are correct
        if(logres == 1) //login success if login returns 1 above, ie. user name and pass are correct
        {
            printf("Login successful!\n\nPlease proceed for booking!\n20 Seats available!");
            printf("\nPlease enter number of seats: ");
            scanf("%d", &seats); 
            bookres = booking(seats, maxseats); //allow booking only if login success, 
												//call booking() with no of seats user enters and max seats 
            if(bookres == 1)//booking() above checks if enough seats are available, returns 1 if available
            {
                printf("\nEnough seats available! Proceed for booking.\n\n");
				//Allow class selection if seats available
                printf("Please select your class:\n");
                printf("1.Enter 1 for AC 1 Tier.\n");
                printf("2.Enter 2 for AC 2 Tier.\n");
                printf("3.Enter 3 for AC 3 Tier.\n");
                printf("4.Enter 4 for Sleeper.\n");
                printf("\nYour choice?: ");
                scanf("%d", &bookch);
                maxseats = bookmenu(bookch, seats, maxseats); //Actual Booking, call to bookmenu()
            }
            else //booking returns 0 if user entered seats exceeds available seats
            {
                printf("Not enough seats!");
            }
        }
        else //login returns 0 if username OR pass is incorrect, comparison fails
        {
            printf("Invalid username or password!");
        }
    }
    else if(usercheck == 2)//user opted for sign-up, logincheck() returns 2
    {
        createuser();//Call user creation module
        system("cls");
        goto A; //continue with login, after user creation
    }
    printf("\n\nThank You for using the Railway booking system. Press any key to exit!");
    getche();
    return 0;
}

int login(char username[], char password[])//login check function, checks if username and pass are correct 
{
    if(!(strcmp(username, "Saurabh")) && !(strcmp(password, "Sau123"))) //string comparison
    {
        return 1;//username and pass are correct, comparison success
    }
    else
    {
        return 0;//Either username or pass or both are incorrect, comparison fails
    }
}

int booking(int seats, int maxseats)//booking function,
{
    if(seats <= maxseats) //checks if number of seats entered by user < = available seats
    {
        return 1;//seats available
    }
    else
    {
        return 0;//seats entered by user is more than available seats
    }
}

int bookmenu(int choice, int seats, int maxseats)//books the selected number of seats in selected class
{
    switch(choice)//Checks which class user has selected, class selected is passed as choice
    {
    case 1: //class 1
    {
        printf("\n%d Seats booked in AC 1 Tier.", seats);
        maxseats = maxseats - seats;//available seats reduced after booking
        printf("\n%d seats remaining!", maxseats);//notify available seats
        break;
    }
    case 2: //class 2 and so on
    {
        printf("\n%d Seats booked in AC 2 Tier.", seats);
        maxseats = maxseats - seats;
        printf("\n%d seats remaining!", maxseats);
        break;
    }
    case 3:
    {
        printf("\n%d Seats booked in AC 3 Tier.", seats);
        maxseats = maxseats - seats;
        printf("\n%d seats remaining!", maxseats);
        break;
    }

    case 4:
    {
        printf("\n%d Seats booked in Sleeper coach!", seats);
        maxseats = maxseats - seats;
        printf("\n%d seats remaining!", maxseats);
        break;
    }

    default:
        printf("\nInvalid class!");
    }
    return maxseats;
}

int logincheck(loginchoice)//checks if user opted for login or sign-up
{
    switch(loginchoice)//user choice
    {
    case 1:
        return 1; //user opted login

    case 2:
        return 2; //user opted sign-up

    default:
        printf("\nInvalid choice!");
        return 0;
    }
}

void createuser()//new user creation module, dummy/lack of a d/b
{
    char usern[10], passwd[10], name[100];
    printf("\nWelcome to new user creation module!\n\n");
    printf("Please enter your name: ");
    fflush(stdin);
    fgets(name, 100, stdin);
    strtok(name, "\n");
    printf("Please enter your desired username: ");
    scanf("%s", usern);
    printf("Please enter a password: ");
    scanf("%s", passwd);
    printf("New user '%s' successfully created! \n\nPress any key to proceed to login.\n", name);
    getch();
}