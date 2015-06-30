//Program to demonstrate the use of nested for loops to draw random patterns
//header files
#include <stdio.h>
#include <conio.h>

//functions used
void triangle(int);//takes no. of rows
void pyramid(int);//takes no. of rows

int main(int argc, char** argv)
{
    int rows;
    //clrscr();
    printf("\nStar Pattern Generation Module!\n");
    printf("===============================\n\n");
    //take no. of rows as input from user
    printf("How many Rows Of Stars do you want in the Triangle/Pyramid?: ");
    scanf("%d", &rows);
    triangle(rows);//Draw triangle
    printf("\n\n==>Press any key to print Pyramid!\n\n");
    getche();
    pyramid(rows);//Draw pyramid
    getche();
    return 0;
}

void triangle(int rows)
{   
    int rowno,stars;
    //clrscr();
    printf("\n==>Generating the Triangle with %d rows",rows);
    printf("\n=======================================\n\n");
    
    //Outer for decides number of rows to draw = rows
    for(rowno = 1; rowno <= rows; rowno++)
    {   
        printf("\n");//to move to next row
        
        //Inner for decides the number of stars on each row = current row number
        for(stars = 1; stars <= rowno; stars++)
        {
            printf("*");
        }
    }
    
}

void pyramid(int rows)
{
    int rowno,stars,spaces;
    //clrscr();
    printf("\n==>Generating the Pyramid with %d rows",rows);
    printf("\n======================================\n\n");
    
    //Outer for decides number of rows to draw = rows
    for(rowno = 1; rowno <= rows; rowno++)
    {   
        printf("\n");//to move to next row
        
        //Inner for loops
        //print spaces before each row = number of rows - current row number
        for(spaces = 1; spaces <= rows - rowno; spaces++)
            {
                printf(" ");
            }
        //print stars in each row = (2*current row number - 1)
        for(stars = 1; stars <= 2*rowno - 1; stars++)
            {
                printf("*");
            }
    }

}