#include"../../Libraries/terminallibrary.h"
#include"../../Libraries/serverlibrary.h"
#include"../../Libraries/cardlibrary.h"
#include"../../Libraries/listlibrary.h"
#include"../../DataStructures/Stack/LinkedListStack.h"
#include<stdio.h>
#include <stdint.h>
#include<stdlib.h>
void FILH_vAddAccount(ST_accountsDB_t* ptr_aAccount)
{
	FILE *loc_ptr_file;
	loc_ptr_file = fopen("C:/Users/moame/OneDrive/Desktop/Payment System/DataBases/Data/accounts.csv","a");
	    fprintf(loc_ptr_file,
			"%.2f,%d,%s\n",
			ptr_aAccount->balance,
			ptr_aAccount->state,
			ptr_aAccount->primaryAccountNumber);

}
void FILH_vAddTransaction(ST_transaction* ptr_tTransaction)
{
	FILE *loc_ptr_file;
	loc_ptr_file = fopen("C:/Users/moame/OneDrive/Desktop/Payment System/DataBases/Data/Transaction.csv","a");
	    fprintf(loc_ptr_file,
			"%s,%s,%s,%s,%.2f,%.2f,%d,%d\n",
			(ptr_tTransaction->cardHolderData).cardHolderName,
			(ptr_tTransaction->cardHolderData).primaryAccountNumber,
			(ptr_tTransaction->cardHolderData).cardExpirationDate,
			(ptr_tTransaction->terminalData).transactionDate,
			(ptr_tTransaction->terminalData).maxTransAmount,
			(ptr_tTransaction->terminalData).transAmount,
			ptr_tTransaction->transactionSequenceNumber,
			ptr_tTransaction->transState);
}
void FILH_vDeleteAllAccounts()
{
	fclose(fopen("C:/Users/moame/OneDrive/Desktop/Payment System/DataBases/Data/accounts.csv","w"));
}
void FILH_vSaveAccounts()
{
	extern ST_accountsDB_t* Glob_aAccounts;
	extern int Glob_nNum;
	FILH_vDeleteAllAccounts();
	for(int i=0;i<Glob_nNum;i++)
	{
		FILH_vAddAccount(Glob_aAccounts+i);
	}
	free(Glob_aAccounts);
	return;
}
void FILH_vDeleteAllTransaction()
{
	fclose(fopen("C:/Users/moame/OneDrive/Desktop/Payment System/DataBases/Data/Transaction.csv","w"));
}
int FILH_vReadAccounts(ST_accountsDB_t** ptr_pAccount)
{
    FILE *loc_ptr_file;
    loc_ptr_file = fopen("C:/Users/moame/OneDrive/Desktop/Payment System/DataBases/Data/accounts.csv", "r");
	(*ptr_pAccount)=malloc(1*sizeof(ST_accountsDB_t));
    ST_accountsDB_t Loc_cpy_aAccountTemp;
	int cpy_nSize=0;
	do
    {
				fscanf(loc_ptr_file,
				   "%f,%d,%s\n",
				   &Loc_cpy_aAccountTemp.balance,
				   &Loc_cpy_aAccountTemp.state,
				   Loc_cpy_aAccountTemp.primaryAccountNumber);
				   
		(*ptr_pAccount)=realloc(*ptr_pAccount,(cpy_nSize+1)*sizeof(ST_accountsDB_t));
		*((*ptr_pAccount)+cpy_nSize)=Loc_cpy_aAccountTemp;
		cpy_nSize++;
    }while(!feof(loc_ptr_file));

    fclose(loc_ptr_file);
	return cpy_nSize;
}
void FILH_vReadAllTransactions()
{
	extern Stack Glob_sTransactions;
	InitStack(&Glob_sTransactions);
	FILE *loc_ptr_file;
    loc_ptr_file = fopen("C:/Users/moame/OneDrive/Desktop/Payment System/DataBases/Data/Transaction.csv", "r");
	ST_transaction ptr_tTransaction;;
	do
    {
	    fscanf(loc_ptr_file,
			"%49[^,],%49[^,],%49[^,],%49[^,],%f,%f,%d,%d\n",
			(ptr_tTransaction.cardHolderData).cardHolderName,
			(ptr_tTransaction.cardHolderData).primaryAccountNumber,
			(ptr_tTransaction.cardHolderData).cardExpirationDate,
			(ptr_tTransaction.terminalData).transactionDate,
			&(ptr_tTransaction.terminalData.maxTransAmount),
			&(ptr_tTransaction.terminalData.transAmount),
			&(ptr_tTransaction.transactionSequenceNumber),
			&(ptr_tTransaction.transState));
			push(&Glob_sTransactions,ptr_tTransaction);
    }while(!feof(loc_ptr_file));
    fclose(loc_ptr_file);
}