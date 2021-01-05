#include<stdio.h>
#include<stdlib.h>
#define PS 5
int f=0,r=-1,item,q[10];
//descending
void insert()
{
    if(r == PS - 1)
        printf("Queue Overflow!\n");
    q[++r] = item;
    sort();
}
void sort()
{
    int i,key,j;
    for (i=1;i<=r;i++)
    {
        key = q[i];
        j = i-1;
        while (j >= 0 && q[j]<key)
        {
            q[j + 1] = q[j];
            j = j - 1;
        }
        q[j + 1] = key;
    }

}
int delete()
{
    if(r == -1)
        printf("Queue Underflow\n");
    else
        return q[f++];

}
void display()
{
    int i;
    if(r == -1)
        printf("\nQUEUE UNDERFLOW!!\n");
    printf("\nThe elements of the queue are:\n");
    for(i=f;i<=r;i++)
    {
        printf("%d\n",q[i]);
    }
}
void main()
{
    int ch;
    for(;;)
    {
        printf("Enter \n1.insertion\n2.deletion\n3.display\n4.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the item to be inserted\n");
                    scanf("%d",&item);
                    insert(item);
                    break;
            case 2: item = delete();
                    if(item == -1)
                        printf("Queue underflow\n");
                    else
                        printf("\nItem popped = %d\n",item);
                    break;
            case 3: display();
                    break;
            default: exit(0);
        }
    }
}
