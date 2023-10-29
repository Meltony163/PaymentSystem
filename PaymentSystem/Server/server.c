#include"../../Libraries/terminallibrary.h"
#include"../../Libraries/cardlibrary.h"
#include"../../Libraries/serverlibrary.h"
#include"../../DataBases/FileHandling/file_handling.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../DataStructures/Stack/LinkedListStack.h"
#include"../../Libraries/stacklibrary.h"

EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t* accountRefrence)
{
	extern ST_accountsDB_t* Glob_aAccounts;
	extern int Glob_nNum;
	Glob_nNum=FILH_vReadAccounts(&Glob_aAccounts);
	for(int i=0;i<Glob_nNum;i++)
	{
		if(strcmp((cardData->primaryAccountNumber),(Glob_aAccounts[i].primaryAccountNumber))==0)
		{
			*accountRefrence=Glob_aAccounts[i];
			return SERVER_OK;
		}
	}
	return ACCOUNT_NOT_FOUND;
}
EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence)
{
	if(accountRefrence->state==1)
	{
		return SERVER_OK;
	}
	return BLOCKED_ACCOUNT;
}

EN_serverError_t isAmountAvailable(ST_terminalData_t *termData,ST_accountsDB_t* accountRefrence)
{
	if((accountRefrence->balance)>=(termData->transAmount))
	{
		return SERVER_OK;
	}
	return LOW_BALANCE;
}

EN_serverError_t saveTransaction(ST_transaction *transData)
{
	extern Stack Glob_sTransactions;
	transData->transactionSequenceNumber=(StackTop(Glob_sTransactions).transactionSequenceNumber)+1;
	FILH_vAddTransaction(transData);
	return APPROVED;
}

void listSavedTransactions(void)
{
	extern Stack Glob_sTransactions;
	TraversStack(Glob_sTransactions);
	return;
}

EN_transStat_t recieveTransactionData(ST_transaction *transData)
{
	ST_accountsDB_t Loc_sCurrentAccount;
	if(isValidAccount(&(transData->cardHolderData),&Loc_sCurrentAccount)==ACCOUNT_NOT_FOUND)
	{
		transData->transState=FRAUD_CARD;
		saveTransaction(transData);
		return ACCOUNT_NOT_FOUND;
	}
	if(isBlockedAccount((transData->cardHolderData,&Loc_sCurrentAccount))==BLOCKED_ACCOUNT)
	{
		transData->transState=DECLINED_STOLEN_CARD;
		saveTransaction(transData);
		return BLOCKED_ACCOUNT;
	}
	if(isAmountAvailable(&(transData->terminalData),&Loc_sCurrentAccount)==LOW_BALANCE)
	{
		transData->transState=DECLINED_INSUFFECIENT_FUND;
		saveTransaction(transData);
		return LOW_BALANCE;
	}
	extern ST_accountsDB_t* Glob_aAccounts;
	extern int Glob_nNum;
	for(int i=0;i<Glob_nNum;i++)
	{
		if(strcmp((Loc_sCurrentAccount.primaryAccountNumber),(Glob_aAccounts[i].primaryAccountNumber))==0)
		{
			printf("HI\n");
			Glob_aAccounts[i].balance=Glob_aAccounts[i].balance-((transData->terminalData).transAmount);
		}
	}
	transData->transState=APPROVED;
	saveTransaction(transData);
	FILH_vSaveAccounts();
	return SERVER_OK;
}