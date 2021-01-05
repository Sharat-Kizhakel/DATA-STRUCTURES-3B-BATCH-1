#include <iostream>

using namespace std;

struct bank
{
int no;
char name[50];
float bal;
float dep;
}b[50];

int i=0,num;
int x=0;
float amt;
int main()
{int ch;
    while(1)
    {

printf("\n\n");
printf("\n****BANKING SYSTEM****");
printf("\nPress 1 for creation");
printf("\nPress 2 for deposit");
printf("\nPress 3 for withdrawal");
printf("\nPress 4 for exit");
printf("\nPlease enter a (valid) choice:");
scanf("%d",&ch);
switch(ch)
{
       case 1:
       printf("\nPlease enter your account number:");
       scanf("%d",&b[i].no);
        printf("\nPlease enter your name:");
       scanf("%s",&b[i].name);
    printf("\nYour minimum deposit is 1000");
       b[i].dep=1000;
       i++;

       break;
       case 2:
        float wid;
printf("\n***DEPOSIT***");
printf("\nPlease enter your account number");
       scanf("%d",&num);
       for(int j=0;j<i;j++)
       if(b[j].no==num)
       {
           x=j;
        printf("\n Account Number : %d",b[x].no);
        printf("\n Name : %s",b[x].name);
        printf("\n Deposit : %f",b[x].dep);
        printf("\n How Much do you want to deposit:");
        scanf("%f",&amt);
      b[x].dep+=amt;
        printf("\nNEW Deposit Amount is :%f",b[x].dep);
       }
       else
       {
           printf("\n ACCOUNT NUMBER IS INVALID");
       }

       break;
       case 3:
  printf("\n****WITHDRAW****");
printf("\nEnter your Account Number");
scanf("%d",&num);
for(int j=0;j<i;j++)
    {
            if(b[j].no == num)
            x = j;
            }
                if(b[x].no == num)
                    {
            printf("\n Account Number : %d",b[x].no);
            printf("\n Name : %s",b[x].name);
            printf("\n Deposit : %f",b[x].dep);
            printf("\n How Much do you want to Withdraw Now:");
            scanf("%f",&wid);
            if(b[x].dep<wid+500)
                {
                printf("\nCANNOT WITHDRAW YOUR ACCOUNT HAS MINIMUM BALANCE");

                    }
                    else
                    {
                                b[x].dep-=wid;
                                printf("\nThe Balance Amount is:%f",b[x].dep);
                    }
                }
                        else
                                 {
                        printf("INVALID account no");

                                 }
       break;
       case 4:exit(0);
       default:printf("Invalid choice");

}
    }
    return 0;
}
