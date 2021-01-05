#include <stdio.h>
#include <stdlib.h>
struct Student
    {
        int student_id[50];
        int age;
        int marks;

    }student[50];
int main()
{int n;
 printf("Enter the number of students:");
 scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
printf("\nEnter the Roll no of the student %d:",(i+1));
   scanf("%d",&student[i].student_id);
    }
  for(int i=0;i<n;i++)
  {
printf("\nEnter the age of the student %d:",(i+1));
     scanf("%d",&student[i].age);
  }
    for(int i=0;i<n;i++)
    {
    printf("\nEnter the marks of the student %d:",(i+1));
    scanf("%d",&student[i].marks);
    }
  for(int i=0;i<n;i++)
  {
      if((student[i].age>20)&&(student[i].marks>=0&&student[i].marks<=100))
      {
          if(student[i].marks>=65)
          {
              printf("\nCongratulations Student %d you have been granted admission\n",(i+1));
          }
          else
          {
              printf("\nSorry Student %d you are not eligible\n",(i+1));
          }
      }
      else
        {
        printf("Sorry Student %d you are not eligible\n",(i+1));
        }
  }
    return 0;
}
