#ifndef LIST_LIBRARY_h
#define LIST_LIBRARY_h
#include "serverlibrary.h"
typedef struct node
{
    ST_accountsDB_t data;
    struct node* link;
}S_node;
#endif