//cq
#include <stdio.h>
#include <stdlib.h>
int size;
struct Queue{
    int front; //Index Of front element in Queue
    int rear; //Index of rear element in Queue
    int *queue; //Base address of array to store Queue
}Q;
//Function to insert an element to rear of Queue
void insert()
{
    int val;
    //Checking if Queue is Full
    if(Q.front==0&&Q.rear==size-1)
    {
        printf("Queue is Full\n");
        printf("Reallocating Memory\n");
        size++;
        Q.queue = (int *)realloc(Q.queue,size*sizeof(int));
    }
    if(Q.front==-1&Q.rear==-1)
        Q.front=0; //Initializing First element
    printf("Enter the element to be inserted : ");
    scanf("%d",&val);
    Q.rear=(Q.rear+1)%size;
    *(Q.queue+Q.rear) = val;
    printf("Insertion Successful\n");
}
//Function to delete the front element of Queue
void delete()
{
    //Checking if Queue is Empty
    if(Q.front==-1)
    {
        printf("Queue is Empty\n");
    }
    else if(Q.front==Q.rear)
    {
        printf("Deleted Element : %d\n",*(Q.queue+Q.front));
        Q.front=Q.rear=-1;
    }
    else
    {
        //Deleting Element from front
        printf("Deleted Element : %d\n",*(Q.queue+Q.front));
        Q.front=(Q.front+1)%size;
    }
}
//Function Display all elements of Queue
void display()
{
    int i;
    //Checking if Queue is Empty
    if(Q.front==-1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        if(Q.front<Q.rear)
        for(i=Q.front;i<=Q.rear;i++)
        {
            printf("%d\n",*(Q.queue+i));
        }
        else
        {
            for(i=Q.front;i<=size-1;i++)
            {
                printf("%d\n",*(Q.queue+i));
            }
            for(i=0;i<=Q.rear;i++)
            {
                printf("%d\n",*(Q.queue+i));
            }
        }
    }
}
void main()
{
    int choice,val;
    Q.front=Q.rear=-1; //Initializing Empty Queue
    printf("Enter the Size : ");
    scanf("%d",&size);
    Q.queue=(int *)malloc(size*sizeof(int)); //Dynamically Allocating Array for Queue
    printf("Main Menu\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    for(;;)
    {
        printf("Enter Your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : insert();
                     break;
            case 2 : delete();
                     break;
            case 3 : display();
                     break;
            case 4 : printf("!! THANK YOU !!\n");
                     exit(0);
            default : printf("Invalid Choice\nEnter Again\n");
        }
    }
}


//dq
#include <stdio.h>
#include <stdlib.h>
int size;
struct Queue
{
    int *queue; //Base address of array to store Queue
    int front; //Index Of front element in Queue
    int rear; //Index of rear element in Queue
}Q;
//Function to insert an element to rear of Queue
void pushrear(int val)
{
    //Checking if Queue is Full
    if(Q.rear==size-1&&Q.front==0||Q.front>Q.rear)
    {
        printf("Queue is Full\n");
        printf("Reallocating Memory\n");
        size++;
        Q.queue = (int *)realloc(Q.queue,size*sizeof(int));
    }
    if(Q.front==-1)
       Q.front=Q.rear=0;
    if(Q.rear==size-1)
    {
        Q.rear = 0;
    }
    else
    {
        Q.rear++;   
    }
    *(Q.queue+Q.rear) = val;
    printf("Insertion Succesfull\n");
}
//Function to insert an element to front of Queue
void pushfront(int val)
{
    //Checking if Queue is Full
    if(Q.rear==size-1&&Q.front==0||Q.front>Q.rear)
    {
        printf("Queue is Full\n");
        printf("Reallocating Memory\n");
        size++;
        Q.queue = (int *)realloc(Q.queue,size*sizeof(int));
    }
    if(Q.front==-1)
    {
        Q.front=Q.rear=0;
    }
    else if(Q.front==0)
    {
        Q.front = size-1;
    }
    else
    {
        Q.front--;
    }
    *(Q.queue+Q.front)=val;
    printf("Insertion Succesfull\n");
}
//Function to delete the front element of Queue
void popfront()
{
    if(Q.front==-1)
    {
        printf("Queue is Empty");
    }
    else
    {
        //Deleting Element from front
        printf("Deleted Element : %d\n",*(Q.queue+Q.front));
    }
    if(Q.front==Q.rear)
    {
        Q.front=Q.rear=-1;
    }
    else if (Q.front==size-1)
    {
        Q.front=0;
    }
    else
    {
        Q.front++;
    }
}
//Function to delete the rear element of Queue
void poprear()
{
if(Q.front==-1)
    {
        printf("Queue is Empty");
    }
    else
    {
        //Deleting Element from rear
        printf("Deleted Element : %d\n",*(Q.queue+Q.rear));
    }
    if(Q.front==Q.rear)
        Q.front=Q.rear=-1;
    
else if(Q.rear == 0)
        Q.rear = size-1;
    else
        Q.rear--;
}
//Function Display all elements of Queue
void display()
{
    int i,fpos=Q.front,rpos=Q.rear;
    //Checking if Queue is Empty
    if(Q.front==-1)
    {
        printf("Queue is Empty");
    }
    if (fpos<=rpos)
    {
        for(i=fpos;i<=rpos;i++)
        printf("%d ",*(Q.queue+i));
    }
    
    else
    {
        for(i=fpos;i<=size-1;i++)
        printf("%d ",*(Q.queue+i));
        fpos=0;
        for(i=fpos;i<=rpos;i++)
        printf("%d ",*(Q.queue+i));
    }
    printf("\n");
}
void main()
{
    Q.front=Q.rear=-1; //Initializing Empty Queue
    int val,choice;
    printf("Enter the Size : ");
    scanf("%d",&size);
    Q.queue=(int *)malloc(size*sizeof(int)); //Dynamically Allocating Array for Queue
    printf("Main Menu\n1.Push-Front\n2.Pop-Front\n3.Push-Rear\n4.Pop-Rear\n5.Display\n6.Exit\n");
    for(;;)
    {
        printf("Enter Your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("Enter the element to be inserted : ");
                     scanf("%d",&val);
                     pushfront(val);
                     break;
            case 2 : popfront();
                     break;
            case 3 : printf("Enter the element to be inserted : ");
                     scanf("%d",&val);
                     pushrear(val);
                     break;
            case 4 : poprear();
                     break;
            case 5 : printf("Queue : ");
                     display();
                     break;
            case 6 : printf("!! THANK YOU !!\n");
                     exit(0);
            default : printf("Invalid Choice\nEnter Again\n");
        }
    }
}


//pq
#include <stdio.h>
#include <stdlib.h>
int size;
struct Queue
{
    int *a; //Base address of array to store Queue
    int front; //Index Of front element in Queue
    int rear; //Index of rear element in Queue
}Q;
//Function to check Priority
int prioritycheck(int X)
{
    int i=0;
    while(*(Q.a+i)<X&&i<=Q.rear)
    {
        i++;
    }
    return i;
}
//Function to insert an element to Queue
void insert(int X)
{
    int i,pos;
    //Checking if Queue is Full
    if(Q.rear==size-1)
    {
        printf("Queue is Full\n");
        printf("Reallocating Memory\n");
        size++;
        Q.a= (int *)realloc(Q.a,size*sizeof(int));//Reallocating Memory for Queue
    }
    if(Q.rear==-1&&Q.front==-1)
    {
        Q.rear=Q.front=0; //Initializing First element
        *(Q.a+Q.rear)=X;
    }
    else
    {
        pos = prioritycheck(X);
        Q.rear++;
        for(i=Q.rear;i>=pos;i--)
        {
            *(Q.a+i)=*(Q.a+i-1);
        } 
        *(Q.a+pos)=X;
    }
}
//Function to delete the front element of Queue
void delete()
{
    if(Q.front==-1)
        printf("Queue is Empty\n");
    else if(Q.front==Q.rear)
    {
        printf("Deleted Element : %d\n",*(Q.a+Q.front));
        Q.front=Q.rear=-1;
    }
    else
    {
        //Deleting Element from front
        printf("Deleted Element : %d\n",*(Q.a+Q.front));
        Q.front++;
    }
}
//Function Display all elements of Queue
void display()
{
    if(Q.front==-1)
        printf("Queue is Empty\n");
    else
    {
        for(int i=Q.front;i<=Q.rear;i++)
        printf("%d ",*(Q.a+i));
        printf("\n");
    }
}
void main()
{
    int choice,val;
    Q.front=-1;Q.rear=-1; //Initializing Empty Queue
    printf("Enter the Size : ");
    scanf("%d",&size);
    Q.a=(int *)malloc(size*sizeof(int)); //Dynamically Allocating Array for Queue
    printf("Main Menu\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    for(;;)
    {
        printf("Enter Your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("Enter the element to be inserted : ");
                     scanf("%d",&val);
                     insert(val);
                     break;
            case 2 : delete();
                     break;
            case 3 : display();
                     break;
            case 4 : printf("!! THANK YOU !!\n");
                     exit(0);
            default : printf("Invalid Choice\nEnter Again\n");
        }
    }
}

