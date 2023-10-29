#ifndef STACK_LIBRARY_h
#define STACK_LIBRARY_h

#include"serverlibrary.h"

typedef struct stacknode{
    ST_transaction data;
    struct stacknode* link;
}node;

typedef  struct stack{
node* top;
}Stack;

#endif