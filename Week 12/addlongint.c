#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("OUT OF MEMORY");
        exit(0);
    }
    return x;
}
NODE insert_front(NODE first,int data)
{

 NODE temp=getnode();
 temp->link=first;
 temp->info=data;
 return temp;
}
NODE extract(char *s,NODE head)
{int n;
    for(int i=0;i<strlen(s);i++)
    {
        n=s[i]-'0';
        head=insert_front(head,n);
    }
    return head;
}
NODE add_long(NODE head1,NODE head2,NODE head3)
{
    int temp;
    int carry=0;
    int sum;
NODE cur1=head1;
NODE cur2=head2;
while(cur1!=NULL&&cur2!=NULL)
{
    temp=cur1->info+cur2->info+carry;
    if(temp>9)
    {
        sum=temp%10;
        carry=temp/10;
    }
    else
    {
        sum=temp;
        carry=0;
    }
    head3=insert_front(head3,sum);
    cur1=cur1->link;
    cur2=cur2->link;
}
while(cur1!=NULL)
{
    temp=cur1->info+carry;
    if(temp>9)
    {
        sum=temp%10;
        carry=temp/10;
    }
    else
    {
    sum=temp;
    carry=0;
    }
    head3=insert_front(head3,sum);
    cur1=cur1->link;
}
while(cur2!=NULL)
{
    temp=cur2->info+carry;
    if(temp>9)
    {
        sum=temp%10;
        carry=temp/10;
    }
    else
    {
        sum=temp;
        carry=0;
    }
    head3=insert_front(head3,sum);
    cur2=cur2->link;
}
 if(cur1==NULL&&cur2==NULL)//once both have reached end of list
   {
         if(carry==1)
         head3=insert_front(head3,carry);
        return head3;
   }

}
void display(NODE first)
{
    NODE cur;
 if(first==NULL)
 {
     printf("The list is empty");
     return;
 }
 else
 {
    cur=first;
 while(cur!=NULL)
 {
     printf("%d ",cur->info);
     cur=cur->link;
}}}
int main()
{
   NODE head1=NULL;
   NODE head2=NULL;
   NODE head3=NULL;
   char s1[30],s2[30];
   printf("\nEnter the first integer:");
   scanf("%s",s1);
   head1=extract(s1,head1);
   display(head1);
   printf("\nEnter the second integer:");
   scanf("%s",s2);
   head2=extract(s2,head2);
   display(head2);
   head3=add_long(head1,head2,head3);
   printf("\nThe result is:");
   display(head3);
    return 0;
}
