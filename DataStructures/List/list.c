#include"../../Libraries/listlibrary.h"
#include"../../Libraries/serverlibrary.h"
void InsertAtBegining(S_node** ptr_pListStart,S_node *cpy_ListNode)
{
    if(*ptr_pListStart==NULL)
    {
		cpy_ListNode->link=NULL;
        *ptr_pListStart=cpy_ListNode;
        return;
    }
    cpy_ListNode->link=*ptr_pListStart;
    *ptr_pListStart=cpy_ListNode;
    return;
}
void DeleteList(S_node** ptr_pListStart)
{
	S_node* Loc_pIterator=*ptr_pListStart;
	while(Loc_pIterator!=NULL)
	{
		*ptr_pListStart=(*ptr_pListStart)->link;
		free(Loc_pIterator);
		Loc_pIterator=*ptr_pListStart;
	}
}