#include <stdio.h>
#include <stdlib.h>

int main()
{
     int a[100]={0};

    int n;
    printf("Input the number of elements of the array:");
        scanf("%d",&n);
        insert_element(a,n);
    return 0;
}

void insert_element(int a[],int n)
{
    // initial array of size 10
    for (int i=0; i<n; i++)
    {
       scanf("%d",&a[i]);
    }
    for (int i=0;i<n; i++)
    {
    printf("%d",a[i]);
    printf("\n");
    }
    int num,pos;
      printf("Please enter the number to be inserted:");
      scanf("%d",&num);
     printf("Please enter the position at which you want to enter the number:");
    scanf("%d",&pos);
     n++;
    for (int i = n; i >= pos; i--)
    {
        a[i]=a[i-1];
    }

a[pos-1]=num;

    // updated array
    for(int i=0;i<n;i++)

     {
    printf("%d\,",a[i]);
    }
}
