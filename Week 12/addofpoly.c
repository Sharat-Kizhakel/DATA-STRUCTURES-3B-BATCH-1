#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
float cf;
float px;
float py;
int flag;
struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("OUT OF MEMORY");
        exit(0);
    }
    return x;
}
NODE insert_rear(float cf,float x,float y,NODE head)
{
   NODE temp;
   NODE cur;
   temp=getnode();
   temp->cf=cf;
   temp->px=x;
   temp->link=NULL;
   temp->py=y;
   temp->flag=0;
   if(head==NULL)
   {
       return temp;
   }
   cur=head;
   while(cur->link!=NULL)
   {
       cur=cur->link;
   }
   cur->link=temp;
  return head;
}
NODE read_poly(NODE head)
{
    float cf,px,py;
    printf("Enter -999 to end the polynomial:");
    for(int i=1;;i++)
    {
        printf("Enter the %d term\n",i);
        printf("Coefficient:");
        scanf("%f",&cf);
        if(cf==-999)
        {
            break;
        }
        printf("power of x:");
        scanf("%f",&px);
        printf("power of y:",&py);
        scanf("%f",&py);
        head=insert_rear(cf,px,py,head);
    }
    return head;
}
void display(NODE head)
{
    NODE temp;
 if(head==NULL)
 {
     printf("Polynomial doesnt exist\n");
 }
 else
 {
     temp=head;
     while(temp->link!=NULL)
     {
printf("(%5.2fx^%3.2fy^%3.2f)+",temp->cf,temp->px,temp->py);
   temp=temp->link;
     }
     printf("(%5.2fx^%3.2fy^%3.2f)",temp->cf,temp->px,temp->py);
 }
}
NODE add_poly(NODE h1,NODE h2,NODE h3)
{
    NODE p1;
    NODE p2;
    float x1,x2;
    float y1,y2;
    float cf1,cf2,cf3;
     p1=h1;
     while(p1!=NULL)
     {
         x1=p1->px;
         y1=p1->py;
         cf1=p1->cf;
         p2=h2;
         while(p2!=NULL)
         {
             x2=p2->px;
             y2=p2->py;
             cf2=p2->cf;
             if(x1==x2&&y1==y2)
             {
                 break;//it will go out of the loop
             }
             p2=p2->link;
        }
       if(p2!=NULL)//when it comes out of loop when power of x and y are equal and the node p2 is not null
       {
           cf3=cf1+cf2;
           p2->flag=1;
           if(cf3!=0)
           {
               h3=insert_rear(cf3,x1,y1,h3);
           }
       }
       else
        {
        h3=insert_rear(cf1,x1,y1,h3);
        }
       p1=p1->link;
     }
     p2=h2;
     while(p2!=NULL)
     {
         if(p2->flag==0)
         {
        h3=insert_rear(p2->cf,p2->px,p2->py,h3);
         }
         p2=p2->link;
     }
     return h3;
}
int main()
{
   NODE h1,h2,h3;
   h1=NULL;
   h2=NULL;
   h3=NULL;
   printf("Enter the first polynomial:\n");
   h1=read_poly(h1);
   printf("Enter the second polynomial:\n");
   h2=read_poly(h2);
   h3=add_poly(h1,h2,h3);
   printf("The first polynomial is:\n");
   display(h1);
   printf("\nThe second polynomial is:\n");
   display(h2);
   printf("\nThe sum of the two polynomials is:\n");
   display(h3);
    return 0;
}
