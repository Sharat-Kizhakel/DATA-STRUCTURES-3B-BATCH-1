#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
//evaluation of postfix
double compute(char symbol,double op1,double op2)
{
    switch(symbol)
    {
        case '+':return op1+op2;
        case '-':return op1-op2;
        case '*':return op1*op2;
        case '/':return op1/op2;
        case '$':
        case '^':return pow(op1,op2);
        }
}
int main()
{
double s[20];
double res;
double op1,op2;
int top,i;
char postfix[20],symbol;
printf("Please enter the postfix expression");
scanf("%s",postfix);
top=-1;
for(int i=0;i<strlen(postfix);i++)
{
    symbol=postfix[i];
    if(isdigit(symbol))
    {
        s[++top]=symbol-'0';
    }
    else
        {
        op2=s[top--];
        op1=s[top--];
    res=compute(symbol,op1,op2);
    s[++top]=res;
        }
}
res=s[top--];
printf("result is :%0.2f",res);
    return 0;
}
