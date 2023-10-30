#include<stdio.h>
#include <stdint.h>
#include<stdlib.h>
#include<string.h>
#include"Libraries/cardlibrary.h"
#include"Libraries/terminallibrary.h"
#include"Libraries/serverlibrary.h"
#include"DataBases/FileHandling/file_handling.h"
#include"PaymentSystem/Server/server.h"
#include"PaymentSystem/Card/card.h"
#include"PaymentSystem/Terminal/terminal.h"
#include"DataStructures/Stack/LinkedListStack.h"
#include"Application/application.h"
Stack Glob_sTransactions;
ST_accountsDB_t* Glob_aAccounts=NULL;
int Glob_nNum=0;
int main()
{
    FILH_vReadAllTransactions();
	int Loc_nChoise;
	printf("Enter 1 for making Transaction\nEnter 2 for listing Saved Transactions\nYour choise:");
	scanf("%d",&Loc_nChoise);
	while((Loc_nChoise!=1)&&(Loc_nChoise!=2))
	{
		printf("Wrong Choise\n");
		printf("Enter 1 for making Transaction\nEnter 2 for listing Saved Transactions\nYour choise:");
		scanf("%d",&Loc_nChoise);
	}
	if(Loc_nChoise==1)
	{
		fflush(stdin);
		appStart();
	}
	else
	{
		listSavedTransactions();
	}
}
