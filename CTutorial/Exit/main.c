// Program to demonstrate the exit function in C
// Header Files
#include <stdio.h>
#include <conio.h>
#include <stdlib.h> //header file for exit() function

int main()
{
    int a;
    // clrscr();
    printf("\nEnter 0: ");
    scanf("%d", &a);

    if(a == 0) // Conditional
    {
        printf("\nYay entered 0! Exiting with suceess!\n");
        // exit(0);
        exit(EXIT_SUCCESS); // same as exit 0, 0 is for success.
    } // Program terminates here.
    else
    {
        printf("\nYou entered something else. Exiting with failure!\n");
        // exit(1);
        exit(EXIT_FAILURE); // same as exit 1, anything other than 0 or EXIT_SUCCESS indicates failure
    } // Program terminates here.
    
    getche();
    return 0; // main() imlicitly calls exit(0) here, the 0 is from 'return 0' indicating success.
              // We could also do 'return EXIT_SUCCESS' or 'return EXIT_FAILURE'.
}
//0,EXIT_SUCCESS and EXIT_FAILURE are status arguments.
//The exit status or return code of a process in computer programming is a 
//small number passed from a child process (or called process) to a parent process (or caller process) 
//when it has finished executing a specific procedure or delegated task.