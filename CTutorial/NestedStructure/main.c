// Program to demo a the use of nested structures, passing nested structures to array as value and reference
// Array of nested structures

// Header files
#include <stdio.h>
#include <conio.h>

// struct declaration
struct Date // Child structure that will be nested within the parent Student structure
{
    int day, mth, yr;
};

struct Student // Main parent structure
{
    char name[50];
    int roll, age;
    float per;
    struct Date dob; // Nested Structure, struct Student has a member of type struct Date
};

// struct declaration using typedef
typedef struct Salary // Child structure that will be nested within the parent Employee structure
{

    float basic, hra, pf, intax, salhand;

} salry;
/* Variables declared along with the typedef struct declaration 
can be used to declare variables of their own type in main() */
// eg salry s1, s2; in main() in place of struct Salary s1, s2; is perfectly valid

typedef struct Employee // Main parent structure
{
    char name[50];
    int id, age;
    struct Salary sal; // Nested Structure, struct Employee has a member of type struct Salary
} emp;
/* Variables declared along with the typedef struct declaration 
can be used to declare variables of their own type in main() */
// eg emp e1, e2; in main() in place of struct Employee e1, e2; is perfectly valid

// functions used
struct Student getStInfo(struct Student stu); // struct return type, initialise structure members
void dispStInfo(struct Student stu);          // display structure members
void getEmpInfo(emp* e);                      // alternatively, void getEmpInfo(struct Employee* e);
void dispEmpInfo(emp* e);                     // alternatively, void dispEmpInfo(struct Employee* e);
void strStudArray(struct Student stu[], int); // Process array of structures

int main()
{
    // clrscr();
    int size;

    struct Date dt; // Can create multiple variables of type struct Date
    // Can be used to access members of struct Date
    // struct Date acts as generic Date structure
    // Same as writing struct Salary s1; Use of typedef allows for the creation of an alias of the struct type

    struct Student stu1; // Can create multiple variables of type struct Student
    // Can be used to access members of struct Student
    /* Can be used to access members of struct Date via 
    the member dob(which itself is of type struct Date) of struct Student*/
    // eg. stu1.dob.day = 10; as dob is a member of struct Student
    // But cannot access members of struct Date via a variable of type struct Date
    // eg stu1.dt.day = 10; is NOT allowed as dt is not a member of struct Student

    struct Student stu2 = { "John", 2, 24, 67.70, { 12, 6, 1991 } }; // Inline initialisation of a nested structure
    // The inner {} are for members of the child struct

    salry s1; // Can create multiple variables of type struct Salary
    // Can be used to access members of struct Salary
    // Same as writing struct Salary s1; Use of typedef allows for the creation of an alias of the struct type

    emp e1; // Can create multiple variables of type struct
            // Same as writing struct Employee e1; Use of typedef allows for the creation of an alias of the struct type
            // Can be used to access members of struct Employee
    /* Can be used to access members of struct Salary via 
       the member sal(which itslef is of type struct Salary) of struct Employee*/
    // eg. e1.sal.basic = 6000; as sal is a member of struct Employee
    // But cannot access members of struct Salary via a variable of type struct Salary
    // eg e1.s1.basic = 6000; is NOT allowed as s1 is not a member of struct Employee

    //========================================================================================
    
    //*Imp Note*: Variables of the child struct types declared above are not of much use on their own.
    // eg. struct Date dt; or Salry s1;
    // They can only be used to access member of the respective child struct
    // eg. dt.day = 10; or s1.basic = 6000;
    // But they cannot be used by the variables of the parent struct to access their(child's) members
    // eg. stu1.dt.day = 10; or e1.s1.basic = 6000; are not valid
    
    /* So, in case of nested structures it should be enough to declare variables of the parent struct type
       and then access members of the child through the child type member declared in the parent
       eg. struct Student stu1; is variable of parent type, 
       it has member of type struct Date (dob)which is of child type
       This member can then be used to access the members of the child type from the variable of the parent type
       eg. stu1.dob.day = 10;*/
       
    /* Hence, in case of nested structures declarations of child type variables should
       only be required in very specialised scenarios which warrant 
       the need for separate initialisation of child type members*/
       
    // We have declared variables of child type struct for purpose of demonstration only
    
    //=========================================================================================

    // Initialising members of struct Date and struct Salary through dt and s1 variables respectively
    // For demonstration only
    dt.day = 26; // Access member of struct Date with dot operator
    dt.mth = 4;
    dt.yr = 1990;

    printf("\nMy Date of Birth is: %d/%d/%d", dt.day, dt.mth, dt.yr);

    s1.basic = 6000; // Access member of struct Salary with dot operator
    s1.hra = 0.3 * s1.basic;
    s1.intax = 0.05 * s1.basic;
    s1.pf = 0.06 * s1.basic;
    s1.salhand = (s1.basic + s1.hra) - (s1.intax + s1.pf);

    printf("\n\nYour Salary Calculation:\n");
    printf("Take Home Salary = Basic + HRA - Income Tax - PF\n");
    printf("= %.2f + %.2f - %.2f - %.2f = %.2f\n", s1.basic, s1.hra, s1.intax, s1.pf, s1.salhand);

    // Access and initialise members of a nested structure
    // User provided value (using dot operator)

    // Pass nested structure to function - as value
    stu1 = getStInfo(stu1); // Pass nested structure (entire struct) as value
    // structure assigment

    // Access and display members of a nested structure
    dispStInfo(stu1); // Pass nested structure (entire struct) as value
    dispStInfo(stu2);

    printf("\n\n======================================================");

    // Access and initialise members of a nested structure
    // User provided value (using arrow(->) operator)

    // Pass nested structure to function - as reference - pass address of structure
    getEmpInfo(&e1); // Pass address of Nested Structure - reference
    dispEmpInfo(&e1);

    printf("\n======================================================");

    // Array of Nested Structures
    printf("\n\nEnter number of Students: ");
    scanf("%d", &size);
    fflush(stdin); // flushes the newline character from cache
    struct Student stu[size];

    strStudArray(stu, size); // Pass array of nested structure as value
    // Size of array passed as value
    // Can also be passed as reference and handled the same way as shown in Structure.C

    getche();
    return 0;
}

struct Student getStInfo(struct Student stu) // Takes struct Student as paramter, return type is a structure as well
{
    printf("\nEnter Student Details.");
    printf("\n======================\n");
    printf("Enter name: ");
    gets(stu.name);
    printf("Enter roll no.: ");
    scanf("%d", &stu.roll); // Access member of struct Student with dot operator
    printf("Enter age: ");
    scanf("%d", &stu.age);
    printf("Enter percentage: ");
    scanf("%f", &stu.per);
    printf("Enter Date of Birth(Day): ");
    scanf("%d", &stu.dob.day); // Access member of struct Date with dot operator via struct Student's dob member
    printf("Enter Date of Birth(Month): ");
    scanf("%d", &stu.dob.mth);
    printf("Enter Date of Birth(Year): ");
    scanf("%d", &stu.dob.yr);
    fflush(stdin);
    return stu; // return struct (struct Student)
}

void dispStInfo(struct Student stu) // Takes struct Student as paramter
{
    printf("\n\nDisplay Student Details.");
    printf("\n========================\n");
    printf("Student Name: ");
    puts(stu.name); // Access member of struct Student with dot operator
    printf("Student Roll No.: %d", stu.roll);
    printf("\nStudent age: %d", stu.age);
    printf("\nStudent percentage: %.2f", stu.per);
    printf("\nStudent Date Of Birth: %d/%d/%d", stu.dob.day, stu.dob.mth, stu.dob.yr);
    // Access member of struct Date with dot operator via struct Student's dob member
}

void getEmpInfo(emp* e) // takes address of type struct Employee as parameter
{                       // e holds the address of the variable of type struct Employee
    // alternatively, void getEmpInfo(struct Employee* e);

    printf("\n\nEnter Employee Details.");
    printf("\n=======================\n");
    printf("Enter Employee Name: ");
    scanf("%s", e->name); // Access member of struct Employee with arrow operator via pointer e
    printf("Enter Employee ID: ");
    scanf("%d", &e->id);
    printf("Enter Employee age: ");
    scanf("%d", &e->age);

    printf("\nEnter Employee Salary Details: \n");
    printf("Enter basic pay: ");
    scanf("%f", &e->sal.basic);
    // Access member of struct Salary with arrow operator via struct Employee's sal member via pointer e

    // Take Home Salary Calculation
    e->sal.hra = 0.3 * e->sal.basic;
    e->sal.intax = 0.05 * e->sal.basic;
    e->sal.pf = 0.06 * e->sal.basic;
    e->sal.salhand = (e->sal.basic + e->sal.hra) - (e->sal.intax + e->sal.pf);
}

void dispEmpInfo(emp* e) // takes address of type struct Employee as parameter
{                        // e holds the address of the variable of type struct Employee
    // alternatively, void dispEmpInfo(struct Employee* e);

    printf("\n\nDisplay Employee Details.");
    printf("\n=========================\n");
    printf("Employee Name: ");
    puts(e->name); // Access member of struct Employee with arrow operator via pointer e
    printf("Employee ID: %d", e->id);
    printf("\nEmployee age: %d", e->age);

    printf("\n\nEmployee Salary Calculation:\n");
    printf("Take Home Salary = Basic + HRA - Income Tax - PF\n");
    printf("================\n");
    printf("= %.2f + %.2f - %.2f - %.2f = %.2f\n", e->sal.basic, e->sal.hra, e->sal.intax, e->sal.pf, e->sal.salhand);
    // Access member of struct Salary with arrow operator via struct Employee's sal member via pointer e
}

void strStudArray(struct Student stu[], int size) 
{   // Takes array of nested structures as parameter and the size of the array
    // Process array of nested structures
    int i;

    for(i = 0; i < size; i++) // Take input for size number of students = size number of nested structures
    {
        stu[i] = getStInfo(stu[i]); // Call getStInfo() with the current [ith] structure in the array
        // getStInfo() will initialise that structure and return it, which gets stored in the ith position in the array
        // via structure assignment
    }

    for(i = 0; i < size; i++) // Print details of size number of students = size number of nested structures
    {
        dispStInfo(stu[i]); // Call dispStInfo() with the current [ith] structure in the array
                            // dispStInfo() will display members of the ith structure in the array
    }
}