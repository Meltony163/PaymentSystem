#include<stdio.h>
#include<stdlib.h>
#include"../../Libraries/serverlibrary.h"
#include"../../Libraries/stacklibrary.h"
void InitStack(Stack* ps)
{
    ps->top=NULL;
    return;
}
void push(Stack *ps,ST_transaction num)
{
    node* temb=(node*)malloc(sizeof(node));
    if(temb==NULL)
    {
        printf("Cant push\n");
    }
    temb->data=num;
    temb->link=ps->top;
    ps->top=temb;
    return;
}
void pop(Stack *ps)
{
    if(ps->top==NULL)
    {
        printf("Stack is Empty\n");
        return;
    }
    node* temb=ps->top;
    ps->top=ps->top->link;
    free(temb);
    return;
}
ST_transaction StackTop(Stack s)
{
    return s.top->data;
}
int StackEmpty(Stack s)
{
    if(s.top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void TraversStack(Stack s)
{
    node* temb=s.top;
    while(temb!=NULL)
    {
        //printf("%d\n",temb->data);
        temb=temb->link;
    }
}
void DestoryStack(Stack *ps)
{
    node* temb;
    while(ps->top!=NULL)
    {
        temb=ps->top;
        ps->top=ps->top->link;
        free(temb);
    }
}
