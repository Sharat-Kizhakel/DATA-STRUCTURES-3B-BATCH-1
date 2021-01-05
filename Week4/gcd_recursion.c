#include <stdio.h>
#include <stdlib.h>
int gcd(int a,int b)
{
    return ((b==0)?a:gcd(b,a%b));
}
int main()
{
    int x,y;
    printf("Please enter the values a and b:");
    scanf("%d",&x);
    scanf("%d",&y);
    int res=gcd(x,y);
    printf("%d",res);
    return 0;
}
