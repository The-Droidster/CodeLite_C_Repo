// Program to demonstrate head and tail recursion using factorial
// header files
#include <stdio.h>
#include <conio.h>
#include <stdlib.h> //header for exit()

// functions used
long int headfact(long int); // for head recursion
long int tailfact(long int, long int); // for tail recursion

int main()
{
    long int n; 
    int ch; 
    long int fact;
    long int prod = 1;
    // clrscr();
    printf("\nFactorial using recursion!");
    printf("\n==========================\n\n");
    printf("Enter the number to find the factorial for: ");
    scanf("%ld", &n);

    if(n < 0) // number canoot be negative
    {
        printf("\nCannot calculate factorial of a negative number! Exiting!");
        exit(EXIT_FAILURE); // exit and terminate program if entered no. is neagtive
    }

    printf("\n\n1. Enter 1 for Head recursion.");
    printf("\n2. Enter 2 for Tail recursion.\n?: ");
    scanf("%d", &ch); // Choice of head or tail recursion

    if(ch == 1)
    {
        fact = headfact(n);
    }
    else if(ch == 2)
    {
        fact = tailfact(n, prod); // prod will accumulate the value of the repititive multiplication
    }
    else
    {
        printf("\nWrong Choice!");
    }

    printf("\n\nThe factorial of %ld is : %ld", n, fact); // Print factorial

    getche();
    return 0;
}

long int headfact(long int n)
{
    if(n > 1)
    {
        return n * headfact(n - 1); // call to recursive function is not the last thing in the function
        // multiply by n is still pending and requires a stack, hence head(not - last) recursion
        // result of headfact(n-1) is recursively returned to the previous calls and in the last return
        // it is multiplied by n and returned to main()
    }
    else if(n <= 1)
    {
        return 1; //(0! and 1! = 1)
    }
    else
    {
        return 0; // Never executed, but for the sake of completeness
    }
}

long int tailfact(long int n, long int prod)
{
    if(n <= 1)
    {
        return prod; // return the accumulated product from recursive calls when n reaches 1(0! and 1! = 1)
    }
    else
        return tailfact(n - 1, prod * n); // The last executed statement is recursive call, hence tail recursion
}

/*The compiler is simply able to transform this

int tailfact(int n, int prod)
{
    if (n <= 1)
    {
        return prod;
    }
    else return tailfact(n-1,prod*n);
}
into something like this:

int tailfact(int n, int prod) {
label:
    if (n <= 1)
    return prod;
    else
    {
    prod = prod * n;
    n--;
    }
    goto label;
}*/