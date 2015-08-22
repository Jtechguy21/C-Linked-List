#include <stdio.h>
#include <stdlib.h>
/*
Author: John Toledo
Written in: C
Linked List(Stack-Version) 

*/

typedef struct stack
{
    int val;
    struct stack* next;

}stack;



//This is my personal preference
//The main purpose of this typedef is to avoid visually seeing double pointers all over the place
//So everytime I refer to Stackptr the program knows that its a pointer to a stack struct
//Not Required when you write your own
typedef stack* stackptr;



//display menu
void dmenu()
{
    printf("Please Select the following stack operation!\n");
    printf("a - [a + int value] to add value to the stack\n");
    printf("r - to remove whats at the top of the stack\n");
    printf("d - to display all values currently on the stack\n");
    printf("s - [S + int value] to search for its existance in the stack\n");
    printf("w - to check the value at the top of the stack\n");
    printf("f - to empty the stack\n");
    printf("e - to exit the program\n");
    printf("\n\n");



}

//checks to see if target value is located anywhere in the stack
void existance(stackptr head,int val)
{

    if((head)==NULL)
    {
        printf("Empty list, nothing to search!!\n");
        return;
    }


    stackptr walker=head;

    while(walker!=NULL)
    {
        if(walker->val==val)
        {
            printf("We found the value %d on the stack\n\n",val);
            break;
        }

        walker=walker->next;
    }



    if(walker!=NULL)
    return;

    else
        printf("Value %d not found on the stack\n\n",val);


}


//pushes new value on the stack
void push(stackptr* head, int val)
{
    stackptr newnode=(stack*)malloc(sizeof(stack));
    newnode->val=val;


    if((*head)==NULL)
    {
        printf("Pushing %d\n\n",val);
        newnode->next=(*head);
        (*head)=newnode;
        return;
    }

    newnode->next=(*head);
    (*head)=newnode;


    printf("Pushing %d\n\n",val);




}

//checks what is the top value on the stack and displays it

void valtop(stackptr head)
{

    if(head==NULL)
    {
        printf("Nothing is currently on the stack!!\n\n");
        return;
    }


    stackptr walker=head;

    printf("The value currently at the top of the stack is %d\n\n",walker->val);




}




//displays all the current value on the stack
void display(stackptr head)
{

    stackptr walker=(head);

    if(head==NULL)
    {
        printf("Empty! nothing is currently on the stack\n");
        return;
    }

    printf("[Curent values on the the stack]\n");

    printf("______\n");

    while(walker!=NULL)
    {
        printf("[ ");
        printf("%d",walker->val);
        printf(" ]\n");
        walker=walker->next;
    }

    printf("\n");


}

//removes the very top element on the stack, and readjusts the head
void removetop(stackptr* head)
{

    if((*head)==NULL)
    {
        printf("Nothing to remove. Empty list !!\n");
        return;
    }


    stackptr temp=(*head);
    stackptr walker=(*head);
    walker=walker->next;

    free(temp);
    (*head)=walker;
    printf("Removing top value successful!\n\n");



}

//empties the whole list
void empty(stackptr* head)
{

    if((*head)==NULL)
    {
        printf("Stack is already empty!!\n");
        return;
    }

    stackptr walker=(*head);
    stackptr temp;

    while(walker!=NULL)
    {
        temp=walker;
        walker=walker->next;
        (*head)=walker;
        free(temp);
    }




}



int main()
{


    printf("Created by: John Toledo\n");
    printf("______________________________________________\n");
    printf("Welcome to Linked list operations[stack]Edition\n");
    printf("_______________________________________________\n");


    stackptr head=NULL;

    int done=0;

    int val;
    char select;

    dmenu();

    while(done==0)
          {
            scanf("%c",&select);
            if(select=='a'||select=='s')
            {
                scanf("%d",&val);
            }


            switch(select)
            {
            case 'a':
            printf("Push operation Selected!\n\n");
            push(&head,val);
            dmenu();
            break;

            case 'r':
            printf("Remove val. top of stack selected!\n\n");
            removetop(&head);
            dmenu();
            break;

            case 'd':
            display(head);
            dmenu();
            break;

            case 's':
            printf("Search for %d in the stack selected!\n",val);
            existance(head,val);
            dmenu();
            break;

            case 'w':
            printf("Val.check top of the stack selected!\n\n");
            valtop(head);
            dmenu();
            break;

            case 'f':
            printf("Empty the stack selected!\n\n");
            empty(&head);
            dmenu();
            break;

            case 'e':
            done=1;
            printf("Exiting program. . . . . \n\n");
            break;


            }







          }




    return 0;
}
