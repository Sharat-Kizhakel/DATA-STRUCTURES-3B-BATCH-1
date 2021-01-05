#include <stdio.h>
struct student {
    char name[50];
    int regno;
    float marks1;
    float marks2;
    float marks3;
    float totalmarks;
    int rank;
} s[150];
int max=0;
int main() {
    int n;
    printf("Please enter how many student details you want:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
    printf("\n****STUDENT INFORMATION****\n");
    printf("Enter details of student %d",(i+1));
    printf("\nEnter name: ");
    scanf("%s",&s[i].name);

    printf("\nEnter roll number: ");
    scanf("%d",&s[i].regno);
    printf("\nEnter marks 1: ");
    scanf("%f", &s[i].marks1);
    printf("\nEnter marks 2: ");
    scanf("%f", &s[i].marks2);
    printf("\nEnter marks 3: ");
    scanf("%f", &s[i].marks3);
      s[i].totalmarks=s[i].marks1+s[i].marks2+s[i].marks3;
  }

  for(int i=0;i<n;i++)
  {
      s[i].rank=i;
  }
   for(int i=0;i<n;i++)///bubble sort
  {
      for(int j=0;j<n-i-1;j++)
      {

        if(s[j].totalmarks<s[j+1].totalmarks)
    {
       int t=s[j].rank;
        s[j].rank=s[j+1].rank;
        s[j+1].rank=t;
    }
    }
  }

  for(int i=0;i<n;i++)
  {
      for(int j=0;j<n-i-1;j++)
      {

        if(strcmp(s[j].name,s[j+1].name)>0)
    {
        int t=s[j].totalmarks;
        s[j].totalmarks=s[j+1].totalmarks;
        s[j+1].totalmarks=t;
      char t1[40];
       strcpy(t1,s[j].name);
    strcpy(s[j].name,s[j+1].name);
    strcpy(s[j+1].name,t1);
      int t2=s[j].regno;
        s[j].regno=s[j+1].regno;
        s[j+1].regno=t2;

    }
    }
  }
for(int i=0;i<n;i++)
{
    printf("\nDisplaying Information:\n");
    printf("\nName:%s",s[i].name);
    printf("\nRoll number: %d\n",s[i].regno);
    printf("\nTotal Marks: %0.2f\n",s[i].totalmarks);
    printf("\nRank is:%d",s[i].rank+1);
}


    return 0;
}
