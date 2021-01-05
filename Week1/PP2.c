#include <stdio.h>
#include <stdlib.h>
struct EMPLOYEE
{
    char name[50];
    float basic;
    float hra;
    float da;
    float pf;
    float gross;
}emp[100];
int main()
{
    int n;
      printf("Please enter how many employees salary details you want:");
      scanf("%d",&n);

 for(int i=0;i<n;i++)
 {
     printf("DETAILS OF EMPLOYEE %d:",(i+1));
    printf("\nEnter name: ");
    scanf("%s",&emp[i].name);
    printf("\nEnter Basic Salary: ");
    scanf("%f",&emp[i].basic);
    printf("\nEnter HRA: ");
    scanf("%f",&emp[i].hra);
    printf("\nEnter D.A.: ");
    scanf("%f",&emp[i].da);

   emp[i].pf=(emp[i].basic*12)/100;

   emp[i].gross=(emp[i].basic+emp[i].da+emp[i].hra+emp[i].pf);
 }

   for(int i=0;i<n;i++)
   {
    printf("\n****SALARY DETAILS****");
    printf("\nName: %s \nBASIC: %f \nHRA: %f \nDA: %f \nPF: %f\nGROSS SALARY: %f",emp[i].name,emp[i].basic,emp[i].hra,emp[i].da,emp[i].pf,emp[i].gross);
   }


    return 0;
}
