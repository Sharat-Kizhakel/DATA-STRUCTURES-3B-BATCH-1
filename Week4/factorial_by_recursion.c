#include <stdio.h>
#include <stdlib.h>
int fact(int n)
{
    return((n==0)?1:(n*fact(n-1)));
}
int main()
{
    int n;
   printf("Please enter the number whose factorial you need to find:");
   scanf("%d",&n);
   int res=fact(n);
   printf("%d",res);
    return 0;
}
