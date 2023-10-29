#ifndef LINKED_LIST_STACK_h
#define LINKED_LIST_STACK_h
#include<stdio.h>
#include<stdlib.h>
#include"../../Libraries/serverlibrary.h"
#include"../../Libraries/stacklibrary.h"

void InitStack(Stack* ps);

void push(Stack *ps,ST_transaction num);

void pop(Stack *ps);

ST_transaction StackTop(Stack s);

int StackEmpty(Stack s);

void TraversStack(Stack s);

void DestoryStack(Stack *ps);

#endif