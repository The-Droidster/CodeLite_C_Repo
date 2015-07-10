//Program to demonstrate use of structures-> declaration, initialisation, access 
//passing struct to function as entire structure, individual value and as reference
//Using array of structures, passed to fucntion as value and reference

//header files
#include <stdio.h>
#include <conio.h>
#include <string.h> //for strcpy();

// struct declaration
// 2 ways of struct template declaration
// 1. Method 1
struct Employee    // It is a good practice to have struct declaration above the main() body
{                  // So that the compiler is aware of the structure before we use it in main()
    char name[50]; // Collection of different datatype
    int id;
    int age;
    float sal;
} emp1; // one way of declaring a variable of type struct Employee

// 2. Method 2
typedef struct Student
{
    char name[50];
    int roll;
    int age;
    float per;
} stu; // Allows for creating a variable of type stu(which in turn is of type struct Student) in main() eg. stu a,b,c;
// Prohibits the use of variable declared here to be used as normal struct variables
// eg. you cannot do stu.roll = 50;

// functions used
void displayInfo(struct Employee emp);
int changeInfo(int, int);
void getInfo(struct Student* stud);    // alternatively, void getInfo(stu* stud);
void dispStInfo(struct Student* stud); // alternatively, void dispStInfo(stu* stud);
void strArray(stu s[], int);           // alternatively, void strArray(struct Student s[], int);
void strArrayPtr(stu* sp, int);        // alternatively, void strArrayPtr(struct Student* sp, int);

int main()
{
    int yrs, size;
    // clrscr();
    // Declaring variables of type struct
    // one way of doing this is shown above that is declaring along with the struct declaration eg. emp1 and stu
    struct Employee emp2;                               // Another way, emp1 is already declared
    struct Employee emp3 = { "Saurabh", 3, 25, 80000 }; // Another way
    // Declaring the struct variable and initialising its member in a single line, follows order
    //Inline initialisation of all members can be done only along with declaration
    //emp 3 = { "Saurabh", 3, 25, 80000 }; is not allowed

    struct Student stu1;
    stu s1; // Another way, Allowed only since we used typedef for struct Student
    // emp1 e1, e2; will not work since we declared struct Employee without typedef
    //stu cannot be used as normal struct variable eg. cannot do stu.roll = 50;

    stu* pS; // Pointer of type stu(which itself is of type struct Student),
    // holds the address of a variable of type struct Student
    // Can also write struct Student *pS;
    // stu and struct Student are almost synonymous
    pS = &s1; // Store address of variable s1(of type stu = struct Student) in pS

    // Accessing and initialising structure members through struct variables
    // Method of inline initialisation is shown above
    // Initialising using dot operator
    strcpy(emp1.name, "John"); // Used the strcpy() function from string.h to initialise char []
    // cannot use emp1.name = "John" for strings, assignment not alllowed
    // Assignment is allowed only for inline initialisation like char name[20] = "John"
    emp1.id = 1; // Static initialisation using dot(.) operator
    emp1.age = 50;
    emp1.sal = 35000.00;

    printf("\nDetails of Employees 1 and 3 are stored in the system!\n");

    // Accepting user defined values
    printf("\nHello Employee 2. Please enter your details.\n\n");
    printf("Enter your name: ");
    gets(emp2.name);
    printf("Enter your ID: ");
    scanf("%d", &emp2.id);
    printf("Enter your age: ");
    scanf("%d", &emp2.age);
    printf("Enter your salary: ");
    scanf("%f", &emp2.sal);

    // Passing structure to function
    // Passing whole structure as value
    printf("\n\nThe details of Employee 1 are: ");
    displayInfo(emp1); // Passing struct variables emp1, emp2 and emp3 as values to displayInfo
    printf("\n\nThe details of Employee 2 are: ");
    displayInfo(emp2); // Entire struct is passed

    // Passing individual member of struct as value
    printf("\n\nThe details of Employee 3 are: ");
    displayInfo(emp3); // Pass struct as value

    printf("\n\nHello, Employee 3 your age is not updated since you joined! ");
    printf("How many years have you worked for the organisation: ");
    scanf("%d", &yrs);
    emp3.age = changeInfo(emp3.age, yrs); // Pass sal member(individual member) of emp3 as value

    printf("\nYour updated details are: ");
    displayInfo(emp3); // Pass struct as value

    printf("\n\n==================================================================");

    // Passing structure as a reference, pass structure address
    getInfo(&stu1);    // Address of struct Student variable stu1 is passed
    dispStInfo(&stu1); // Address of struct Student variable stu1 is passed

    // Accessing and initialising structure members through a pointer
    // Using pS from above to access member of struct Student via s1
    // Using hard-coded values
    strcpy(pS->name, "Sneha");
    pS->roll = 10; // Static initialisation using arrow(->) operator
    pS->age = 16;  // Using pS to indirectly initialise the members of s1 as pS holds the address of s1
    pS->per = 79.00;

    printf("\n\nUsing Hardcoded Values here! Struct passed as reference!");
    dispStInfo(&s1); // Address of struct Student variable s1 is passed - Reference

    // An Array of structures
    printf("\n\nEnter number of students(Array of Structres passed as value): ");
    scanf("%d", &size);
    stu s[size]; // Declared an array of structures of size, 'size' number of structures of type stu(struct Student)

    strArray(s, size); // Pass array of structures(of type stu or struct Student) as value
    // Size of array passed as value

    printf("\n\nEnter number of students(Array of Structres passed as reference): ");
    scanf("%d", &size);
    stu sp[size];

    strArrayPtr(sp, size); // Pass array of structures(of type stu or struct Student) as reference
    // Base address of the array passed
    // Size of array passed as value

    getche();
    return 0;
}

void displayInfo(struct Employee emp) // Takes entire struct as parameter - passed as value
{
    printf("\n\nDisplay Employee Details.\n");
    printf("=========================\n");
    printf("Employee name: ");
    puts(emp.name);
    printf("Employee id: %d", emp.id);
    printf("\nEmployee age: %d", emp.age);
    printf("\nEmployee salary: %.2f", emp.sal);
}

int changeInfo(int age, int yrs) // Takes individual struct values as normal values
{
    return age + yrs;
}

void getInfo(struct Student* stud) // takes address of type struct Student as parameter
{                                  // alternatively, void getInfo(stu* stud)
    printf("\n\nEnter Student Details.\n\n");
    printf("Enter Student Name: ");
    scanf("%s", stud->name); // using arrow(->) operator to access members of the passed struct variable via pointer
    printf("Enter Student Roll No.: ");
    scanf("%d", &stud->roll);
    printf("Enter Student age: ");
    scanf("%d", &stud->age);
    printf("Enter Student percentage: ");
    scanf("%f", &stud->per);
}

void dispStInfo(struct Student* stud) // takes address of type struct Student as parameter
{                                     // alternatively, void dispStInfo(stu* stud)
    printf("\n\nDisplay Student Details.\n");
    printf("========================\n");
    printf("Student Name: %s", stud->name);
    // using arrow(->) operator to access members of the passed struct variable via pointer stud
    printf("\nStudent Roll No.: %d", stud->roll);
    printf("\nStudent age: %d", stud->age);
    printf("\nStudent percentage: %.2f", stud->per);
}

void strArray(stu s[], int size) // Takes array of structures as parameter and the size of the array
{                                // alternatively, void strArray(struct Student s[], int);
    // Process array of structures
    int i;
    for(i = 0; i < size; i++) // Take input for size number of students = size number of structures
    {
        printf("\nEnter Details for Student %d\n\n", i + 1);
        printf("Enter Student Name: ");
        scanf("%s", s[i].name); // Accessing member of the ith structure in the array
        printf("Enter Student Roll No.: ");
        scanf("%d", &s[i].roll);
        printf("Enter Student age: ");
        scanf("%d", &s[i].age);
        printf("Enter Student percentage: ");
        scanf("%f", &s[i].per);
    }

    for(i = 0; i < size; i++) // Print details of size number of students = size number of structures
    {
        printf("\n\nDisplay Details of Student %d.\n", i + 1);
        printf("=============================\n");
        printf("Student Name: %s", s[i].name); // Accessing member of the ith structure in the array
        printf("\nStudent Roll No.: %d", s[i].roll);
        printf("\nStudent age: %d", s[i].age);
        printf("\nStudent percentage: %.2f", s[i].per);
    }
}

void strArrayPtr(stu* sp, int size) // Takes base address of array of structures as parameter and the size of the array
{                                   // alternatively, void strArrayPtr(struct Student* sp, int);
    // Process array of structures
    int i;
    stu* temp = sp; // temporarily hold address in sp(base address of array)

    for(i = 0; i < size; i++) // Take input for size number of students = size number of structures
    {
        printf("\nEnter Details for Student %d\n\n", i + 1);
        printf("Enter Student Name: ");
        scanf("%s", sp->name);
        // Pointer sp used to access(arrow operator) member of the current [ith] structure in the array
        printf("Enter Student Roll No.: ");
        scanf("%d", &sp->roll);
        printf("Enter Student age: ");
        scanf("%d", &sp->age);
        printf("Enter Student percentage: ");
        scanf("%f", &sp->per);
        sp++; // Increment the pointer to point to the next structure in the array
    }

    // First loop increments sp pointer to end of the array
    sp = temp; // Reset sp to hold the base address of the array again

    for(i = 0; i < size; i++) // Print details of size number of students = size number of structures
    {
        printf("\n\nDisplay Details of Student %d.\n", i + 1);
        printf("=============================\n");
        printf("Student Name: %s", sp->name);
        // Pointer sp used to access(arrow operator) member of the current [ith] structure in the array
        printf("\nStudent Roll No.: %d", sp->roll);
        printf("\nStudent age: %d", sp->age);
        printf("\nStudent percentage: %.2f", sp->per);
        sp++; // Increment the pointer to point to the next structure in the array
    }
}
