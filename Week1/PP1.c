#include <stdio.h>
#include <stdlib.h>
struct Student
{
    int marks1;
    int marks2;
    int marks3;
    int marks4;
    int marks5;
    int total_marks;
}student[100];
int main()
{
    int n;

    printf("please enter the number of students:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
       printf("Enter the marks of Student %d in subject 1:",(i+1));
       scanf("%d",&student[i].marks1);
       printf("\nEnter the marks of Student %d in subject 2:",(i+1));
       scanf("%d",&student[i].marks2);
       printf("\nEnter the marks of Student %d in subject 3:",(i+1));
       scanf("%d",&student[i].marks3);
       printf("\nEnter the marks of Student %d in subject 4:",(i+1));
       scanf("%d",&student[i].marks4);
       printf("\nEnter the marks of Student %d in subject 5:",(i+1));
       scanf("%d",&student[i].marks5);
       printf("\n");
    student[i].total_marks=student[i].marks1+student[i].marks2+student[i].marks3+student[i].marks4+student[i].marks5;

    }
    for(int i=0;i<n;i++)
    {
        printf("Student %d total marks are:%d \n",(i+1),student[i].total_marks);
    }

    return 0;
}
