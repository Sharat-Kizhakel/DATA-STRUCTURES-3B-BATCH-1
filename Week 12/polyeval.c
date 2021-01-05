#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    float cf;
    float px;
    float py;
    struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Out of memory");
        exit(0);
    }
    return x;
}
NODE insert_rear(float cf,float x,float y,NODE head)
{
    NODE temp,cur;
    temp=getnode();
    temp->px=x;
    temp->py=y;
    temp->cf=cf;
    cur=head->link;
    while(cur->link!=head)
    {
        cur=cur->link;
    }
    cur->link=temp;
    temp->link=head;
    return head;
}
NODE read_poly(NODE head)
{
    int i;
    float cf,px,py;
    printf("Enter the coefficient as -999 to end polynomial\n");
for(int i=0;;i++)
{
    printf("Enter the %d term:",i+1);
    printf("coefficient:");
    scanf("%f",&cf);
    if(cf==-999)
        break;
    printf("Power of x:");
    scanf("%f",&px);
    printf("Power of y:");
    scanf("%f",&py);
    head=insert_rear(cf,px,py,head);
 }
 return head;
}

float evaluate(NODE head)
{
    float x,y,sum=0;
    NODE poly;
    printf("Enter the value of x:");
    scanf("%f",&x);
     printf("Enter the value of y:");
    scanf("%f",&y);
    poly=head->link;
    while(poly!=head)
    {
        sum=sum+poly->cf*pow(x,poly->px)*pow(y,poly->py);
       poly=poly->link;
    }
    return sum;
}
void display(NODE head)
{
    if(head->link==head)
    {
        printf("Polynomial doesnt exist");
        return;
    }
    NODE temp=head->link;
    while(temp->link!=head)
    {
    printf("(%5.2fx^%3.1fy^%3.1f)+",temp->cf,temp->px,temp->py);
   temp=temp->link;
    }
       printf("(%5.2fx^%3.1fy^%3.1f)",temp->cf,temp->px,temp->py);//to avoid plus in last term
    printf("\n");
}
int main()
{
    NODE head;
    head=getnode();
    head->link=head;
    float res;
    printf("Enter the polynomial\n");
    head=read_poly(head);
    res=evaluate(head);
    printf("The given Polynomial is:\n");
    display(head);
    printf("The result is:%.2f\n",res);


    return 0;
}
