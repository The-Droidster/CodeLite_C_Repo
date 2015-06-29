

#include <stdio.h>
#include <conio.h>
#include <unistd.h>

int total(int, int, int, int, int);
int avrg(int);
float prcnt(int);
void grade(float, char[]);

int main()
{

  int eng, mat, c, jav, db, tot, avg, rno;
  float per;
  char name[100];
  system("cls");
  printf("\n\nWelcome to student marksheet generation module!");
  printf("\n===============================================\n\n");
  printf("Enter your name: ");
  fgets(name, 100, stdin);
  strtok(name, "\n");
  printf("\nEnter your roll number: ");
  scanf("%d", &rno);
  printf("\n\nHello, %s Please enter your subjectwise marks out of 100: \n", name);
  printf("\nEnglish: ");
  scanf("%d", &eng);
  printf("\nMath: ");
  scanf("%d", &mat);
  printf("\nC Prog: ");
  scanf("%d", &c);
  printf("\nJava Prog: ");
  scanf("%d", &jav);
  printf("\nDatabase: ");
  scanf("%d", &db);
  if(eng > 100 || mat > 100 || c > 100 || jav > 100 || db > 100)
  {
    printf("\n\nInvalid marks entered. Must be out of 100.");
  }
  else
  {
    system("cls");
    printf("\n\n\nGenerating Your Marksheet...");
    printf("\n============================");
    sleep(2);
    // freopen("marksheet.txt","w",stdout);
    printf("\n\nStudent Details:");
    printf("\n----------------");
    printf("\n\nStudent Name: %s\nStudent Roll No.: %d", name, rno);
    printf("\n========================================\n");
    printf("\nYour Subjectwise Marks:");
    printf("\n-----------------------\n\n");
    printf("English\tMaths\tC-Prog\tJava\tDatabase");
    printf("\n\n%d/100\t%d/100\t%d/100\t%d/100\t%d/100", eng, mat, c, jav, db);
    printf("\n========================================\n");
    tot = total(eng, mat, c, jav, db);
    printf("\n========================================");
    printf("\nTotal Marks = %d/500", tot);
    printf("\n========================================");
    avg = avrg(tot);
    printf("\nAverage Marks = %d/100", avg);
    printf("\n========================================");
    per = prcnt(tot);
    printf("\nPercentage: %.2f %%", per);
    printf("\n========================================\n");
    printf("\nGrade: ");
    grade(per, name);
  }
  getche();
  return 0;
}

int total(int eng, int mat, int c, int jav, int db)
{
  return (eng + mat + c + jav + db);
}

int avrg(int tot)
{
  return (tot / 5);
}

float prcnt(int tot)
{
  return (((float)tot / 500) * 100);
}

void grade(float per, char name[])
{
  if(per <= 100.00 && per >= 75.00)
  {
    printf("Congratulations '%s' you have passed with 'Distinction'!", name);
  }
  else if(per < 75.00 && per >= 60.00)
  {
    printf("Congratulations '%s' you have passed with 'First Class'!", name);
  }
  else if(per < 60.00 && per >= 35.00)
  {
    printf("Congratulations '%s' you have passed with Pss Class!", name);
  }
  else
  {
    printf("You have failed '%s'! Don't lose heart!", name);
  }
}
