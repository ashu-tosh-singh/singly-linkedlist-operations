#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<process.h>
#include <stdbool.h>

/*structure declaration*/
struct node
{
    int data; 
    struct node *next;
};

/*represent the head and tail of the linked list*/
struct node *head,*tail=NULL;
int size=0;

/*creating list*/
void addNode(int data)
{
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));  
    newNode->data=data;  
    newNode->next=NULL;  
      
    /*checks if the list is empty*/ 
    if(head==NULL)
    {  
        /*if list is empty, both head and tail will point to new node*/ 
        head=newNode;  
        tail=newNode;  
    }  
    else
    {  
        /*newNode will be added after tail such that tail's next will point to newNode*/
        tail->next=newNode;

        /*newNode will become new tail of the list*/ 
        tail=newNode;  
    }

    /*size will count the number of nodes present in the list*/
    size++;
}

/*reverseList() will reverse the linked list*/
struct node* reverseList(struct node *temp)
{
    struct node *current=temp;
    struct node *prevNode=NULL, *nextNode=NULL;

   /*swap the previous and next nodes of each node to reverse the direction of the list*/
    while(current != NULL)
    {
        nextNode=current->next;
        current->next=prevNode;
        prevNode=current;
        current=nextNode;
    }
    return prevNode;
}

/*isPalindrome() will check whether the given list is palindrome or not*/
void isPalindrome()
{
    struct node *current=head;
    bool flag=true;

    /*Store the mid position of the list*/
    int mid=(size%2==0) ? (size/2):((size+1)/2);
    int i;

    /*reverse the list after middle node to end*/
    struct node *revHead;
    revHead=reverseList(current->next);

    /*finds the middle node in given list*/
    for(i=1; i<mid; i++)
        current=current->next;

    /*compare nodes of first half and second half of list*/
    while(head!=NULL && revHead!=NULL)
    {
        if(head->data != revHead->data)
        {
            flag=false;
            break;
        }
        head=head->next;
        revHead=revHead->next;
    }

    if(flag)
        printf("YOUR LINKED LIST IS PALINDROME\n");
    else
        printf("YOUR LINKED LIST IS NON-PALINDROME\n");
}

/*display() will display all the nodes present in the list*/  
void display()
{
    struct node *current=head;    /*pointing to head*/
      
    if(head == NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }
    printf("NODES OF THE LIST: ");
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;        /*incrementing pointer*/
    }
    printf("\n");
}
      
int main()
{
    int choice,n,m,i;
    while(1)
    {
        printf("\n");
        printf("1. Add Node.\n");
        printf("2. Display.\n");
        printf("3. Check for palindrome or not.\n");
        printf("4. Quit.\n");

        printf ("\nEnter your choice:");
        scanf ("%d",&choice);

        switch (choice)
        {
            case 1:
            printf ("\n\nHow many nodes you want: ");
            scanf ("%d",&n);
            printf("\n");
            for(i = 0;i<n;i++)
            {
                printf ("Enter the element: ");
                scanf ("%d",&m);
                addNode(m);
            }
            break;

            case 2:
            display();
            break;

            case 3:
            isPalindrome();
            break;

            case 4:
            exit(0);

            default:
            printf ("WRONG CHOICE\n");
        }
    }
}



/*
OUTPUT.......................................................................................................
.............................................................................................................

1. Add Node.
2. Display.
3. Check for palindrome or not.
4. Quit.

Enter your choice:1


How many nodes you want: 5

Enter the element: 1
Enter the element: 2
Enter the element: 3
Enter the element: 2
Enter the element: 1

1. Add Node.
2. Display.
3. Check for palindrome or not.
4. Quit.

Enter your choice:2
NODES OF THE LIST: 1 2 3 2 1

1. Add Node.
2. Display.
3. Check for palindrome or not.
4. Quit.

Enter your choice:3
YOUR LINKED LIST IS PALINDROME

1. Add Node.
2. Display.
3. Check for palindrome or not.
4. Quit.

Enter your choice:5
WRONG CHOICE

1. Add Node.
2. Display.
3. Check for palindrome or not.
4. Quit.

Enter your choice:4

D:\c programming>    */