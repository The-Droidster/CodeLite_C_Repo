//Program to demonstrate the use of arrays - declare,access and pass as parameters
//header files
#include <stdio.h>
#include <conio.h>

//functions used
void getinfo(int[]); //takes an entire array as parameter - value
void printinfo(int*); //takes the base address of an array as parameter - reference
int add(int,int); //takes individual array elements as parameters - value

int main()
{
    int i,n,val;
    int size;
    
    //array demo
    printf("\nEnter the size of the array: ");
    scanf("%d",&size); //Array size can be user defined or fixed
    
    //array declaration and initialisation
    
    //int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //declare an integer array of size 10 and initialise(all elements at once) it inline
    //Arrays of fixed size as above can be initialised inline(One way of doing array initialisation)
    int arr[size]; //Declare user defined variable sized array
    
    //more arrays for passing as parameters - Demo array passing to functions
    int stud[3];
    int adder[2];
    
    //clrscr();
    
    //store and access all elements of the array throug a loop
    printf("\nInitialising and Printing all elements of array arr[%d]\n",size);
    for(i = 0; i < size; i++)//loop traverses the array 'element by element' from index 0 to size of array
    {   
        arr[i] = i; //Initialize elements of the array
        printf("arr[%d] = %d\n",i,arr[i]); //array index is numbered from 0 onwards, print the initialised element of the array
    }
    
    printf("\n=======================================================================\n");
    
    //store and access individual elements elements of array
    //clrscr();
    printf("\nEnter the element number you want to change the value of: ");
    scanf("%d",&n);
    if(n > size-1 || n < 0) // array index cannot be negative or more than the size of the array
    {
    printf("\nArray index out of bounds!");   
    }
    else
    {
    printf("The value of the %dth element is currently: arr[%d]: %d",n,n-1,arr[n-1]); //array index starts from 0
    printf("\nEnter the new value you want to assign to arr[%d]: ",n-1);
    scanf("%d",&val);
    printf("Changing the value of the %dth element of array to %d.",n,val);
    arr[n-1] = val; //access and manipulate 'individual element' of the array selectively
    printf("\nThe value of the %dth element of the array is now: arr[%d] = %d",n,n-1,arr[n-1]); //print the changed value
    }
    
    printf("\n\n=======================================================================");
    
    //Demo passing arrays to functions.
    //Pass individual elements of the array as values
    //clrscr();
    printf("\n\nAddition using array elements passed as values to add().");
    printf("\n\nEnter first number: ");
    scanf("%d",&adder[0]); //access individual array elements
    printf("Enter second number: ");
    scanf("%d",&adder[1]); //access individual array elements
    adder[2] = add(adder[0],adder[1]); //individual array elements passed as values to add()
    printf("\nThe result of addition is %d",adder[2]);//result of addition stored in adder[2], return value of add()
    
    printf("\n\n=======================================================================");
    
    //Pass entire array as value
    //clrscr();
    printf("\n\nInvoked getinfo() with array stud[] as parameter(pass by value)");
    getinfo(stud);//passing array stud to getinfo()
    
    printf("\n=======================================================================\n");
    
    getche();
    return 0;
}

int add(int a, int b) //The add function takes int values
{                      
    return a + b;     //Process individual array elements as int values
}

void getinfo(int stud[]) //Takes array as argument - value
{   
    //store int student details in stud[] array
    
    printf("\n\nEnter student details.");
    printf("\n======================");
    printf("\nEnter student ID: ");
    scanf("%d",&stud[0]); //access and store individual array element
    printf("Enter student age: ");
    scanf("%d",&stud[1]); //access and store individual array element
    printf("Enter student marks: ");
    scanf("%d",&stud[2]); //access and store individual array element
    
    //Pass array as pointer/reference
    printf("\n\nInvoked printinfo() with base address of array stud[] as parameter(pass by reference)");
    printinfo(stud);//passing array stud as a reference/pointer
}

void printinfo(int* stud) //Takes base address of the array as argument - reference
{   
    //Display elements of stud[] array
    
    printf("\n\nDisplaying student details.");
    printf("\n===========================");
    
    //The stud pointer holds the base address of the array stud and 
    //the compiler can access the array elements using it
    printf("\nStudent ID: %d",stud[0]); //access and display individual array element
    printf("\nStudent age: %d",stud[1]); //access and display individual array element
    printf("\nStudent marks: %d",stud[2]); //access and display individual array element
} 