#include <stdio.h>
#include<stdlib.h>
//Structure for a single Node
struct node 
{
    int item;
    struct node * next; //Pointer to next Node
    struct node * prev; //Pointer to Previous Node
};
//struct node * type defined as NODE
typedef struct node * NODE;
//Function to create a Node
NODE getnode(int val)
{
    NODE temp; //Pointer to newly created node
    temp = (NODE)malloc(sizeof(struct node));
    temp->item=val;
    temp->next=temp;
    temp->prev=temp;
    return temp;
}
//Function to insert Node at front
NODE insertfront(NODE head,int val)
{
    NODE temp; //Pointer to newly created node
    temp = getnode(val);
    NODE first = head->next;
    if(head->next==NULL)
    {
        head->next = head->prev = temp;
        temp->prev = temp->next = head;
        return head;
    }
    else
    {
        temp -> next = first;
        first->prev = temp;
        temp -> prev = head;
        head->next=temp;
        return head;
    }
}
//Function to insert Node at Rear End
NODE insertrear(NODE head, int val)
{
    NODE temp,last;
    temp = getnode(val); //Pointer to newly created node
    last = head->prev; //Pointer to Current Node
    if(head->next==NULL)
    {
        head->next = head->prev = temp;
        temp->prev = temp->next = head;
        return head;
    }
    else
    {
        last->next=temp;
        temp->next=head;
        head->prev=temp;
        temp->prev=last;
        return head;
    }
}
//Function to delete Node at front
NODE deletefront(NODE head)
{
    NODE first=head->next;
    if(head->next==NULL)
    {
        printf("List is empty\n");
        return head;
    }
    else
    {
        head->next=first->next;
        free(first);
        return head;
    }
}
//Function to delete Node at Rear End
NODE deleterear(NODE head)
{
    NODE last = head->prev; //Pointer to Current Node
    NODE temp=NULL; //Pointer to Previous Node
    if(head->next==NULL)
    {
        printf("List is empty\n");
        return head;
    }
    else
    {
        head->prev=last->prev;
        free(last);
        return head;
    }
}
int search(NODE head, int key)
{
    int i=1,flag=0,pos=0;
    NODE cur;
    cur = head->next;
    while(cur->next!=head)
    {
        if(cur->item==key)
        {
            flag = 1;
            pos = i;
            break;
        }
        cur = cur->next;
        i++;
    }
    if(flag==1)
    return pos;
    else
    return 0;
}
//Function to delete a Key element in a list
NODE deletebykey(NODE head,int key)
{
    int pos = search(head,key); //Position of the found Key
    if(pos!=0)
    {
        head = deletepos(head,pos);
        return head;
    }
    else
    {
        printf("Element not found\n");
        return head;
    }
}
//Function to display all elements in a list
NODE display(NODE head)
{
    NODE cur=head->next;
    if(head->next==NULL)
    {
        printf("List is Empty\n");
        return head;
    }
    else
    {
        while (cur!=head)
        {
            printf("%d ",cur->item);
            cur = cur->next;
        }
        return head;
    }
}
NODE orderlist(NODE head, int val)
{
    NODE temp = getnode(val);
    NODE previous = NULL;
    NODE cur = head->next;
    while(cur->next!=head)
    {
        if(cur->item>temp->item)
        {
            break;
        }
        previous=cur;
        cur = cur->next;
    }
    temp->next = cur;
    temp->prev = previous;
    previous->next = temp;
    cur->prev=temp;
    return head;
}
void main()
{
    NODE head = getnode(0); //Pointer to header node of list
    NODE copy = getnode(0); //Poiner to header node of copied list 
    int choice;
    int key,val,pos;
    printf("\nMain Menu\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Search\n6.Delete By Key\n7.Display\n8.Ordered List\n9.Exit\n");
    for(;;)
    {
        printf("\nEnter your Choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("Enter the value : ");
                     scanf("%d",&val);
                     head = insertfront(head,val);
                     break;
            case 2 : printf("Enter the value : ");
                     scanf("%d",&val);
                     head = insertrear(head,val);
                     break;
            case 3 : head = deletefront(head);
                     printf("Deletion Successfull\n");
                     break;
            case 4 : head = deleterear(head);
                     printf("Deletion Successfull\n");
                     break;
            case 5 : printf("Enter the Key : ");
                     scanf("%d",&key);
                     pos = search(head,key);
                     if(pos!=0)
                     printf("The Key found at %d pos\n",pos);
                     else
                     printf("Element not found\n");
                     break;
            case 6 :printf("Enter the Key : ");
                     scanf("%d",&key);
                     head = deletebykey(head,key);
                     printf("Deletion Successfull\n");
                     break;
            case 7 :display(head);
                     break; 
            case 8 :  printf("Enter the value : ");
                     scanf("%d",&val);
                      head = orderlist(head,val);
                      break;
            case 9 :  printf("!!THANK YOU!!\n");
                     exit(0);
            default : printf("Invalid Choice\n Enter again\n");
        }
    }
}
