/*A program that will read a list of numbers without printing them until a negative number is  encountered.*/
/* When the program scans a negative number then it prints previous items from the list in  reverse order If there is no item to print then print an error message and stop the program). */

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head=NULL;
struct Node *tail=NULL;

int Listsize(struct Node *head)
{
    struct Node *temp;
    temp=head;
    int count=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return count;
}

void push(int item)
{
    struct Node *temp,*ptr;

    temp=(struct Node*)malloc(sizeof(struct Node));

    temp->data=item;
    if(head==NULL)
    {
        head=temp;
        temp->next=NULL;
    }
    else
    {
        ptr=head;
        temp->next=ptr;
        head=temp;
    }
}


int pop()
{
    struct Node *temp;
    int a;
    if(head==NULL)
   {
    printf("Stack empty \n");
    }
    else
    {
        temp=head;
        a=head->data;
        head=head->next;
        free(temp);
    }
    return a;
}

int main()

{
    printf("Input list of number: ");
    while(1)
    {
        int a;
        scanf("%d",&a);
        if(a>=0)
        push(a);
        else if(Listsize(head)==0)
        {
            printf("Error !!!!\n");
        break;
        }
        else
        {
            while(Listsize(head)!=0)
            {
                printf("%d ",pop());
            }
        }
    }
}

