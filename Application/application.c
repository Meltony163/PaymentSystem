#include<stdio.h>
#include <stdint.h>
#include<stdlib.h>
#include<string.h>
#include"../Libraries/cardlibrary.h"
#include"../Libraries/terminallibrary.h"
#include"../Libraries/serverlibrary.h"
#include"../DataBases/FileHandling/file_handling.h"
#include"../PaymentSystem/Server/server.h"
#include"../PaymentSystem/Card/card.h"
#include"../PaymentSystem/Terminal/terminal.h"
#include"../DataStructures/Stack/LinkedListStack.h"
void appStart()
{
	ST_cardData_t Loc_cCard;
    ST_terminalData_t Loc_tTerminal;
    printf("Enter CardHolder Name:");
    while(getCardHolderName(&Loc_cCard)==WRONG_NAME)
    {
        printf("Wrong Name\n");
        printf("Enter CardHolder Name:");
    }
    printf("Enter Card expiration date:");
    while(getCardExpiryDate(&Loc_cCard)==WRONG_EXP_DATE)
    {
        printf("Wrong Expiry Date\n");
        printf("Enter Card expiration date:");
    }
    printf("Enter card primary number:");
    while(getCardPAN(&Loc_cCard)==WRONG_PAN)
    {
        printf("Wrong PAN\n");
        printf("Enter card primary number:");
    }
    printf("Enter transaction date:");
    while(getTransactionDate(&Loc_tTerminal)==WRONG_DATE)
    {
        printf("Wrong Expiry Date\n");
        printf("Enter transaction date:");
    }
    if(isCardExpired(&Loc_cCard,&Loc_tTerminal)==EXPIRED_CARD)
    {
        printf("Expired card");
        return ;
    }
    setMaxAmount(&Loc_tTerminal,10000);
    printf("Enter transaction amount:");
    while(getTransactionAmount(&Loc_tTerminal)==INVALID_AMOUNT)
    {
        printf("Wrong amount\n");
        printf("Enter transaction amount:");
    }
    if(isBelowMaxAmount(&Loc_tTerminal)==EXCEED_MAX_AMOUNT)
    {
        printf("Transaction amount exceeds maximum amount\n");
        return ;
    }
    ST_transaction Loc_tTransaction;
    Loc_tTransaction.cardHolderData=Loc_cCard;
    Loc_tTransaction.terminalData=Loc_tTerminal;
    Loc_tTransaction.transState=1;
    Loc_tTransaction.transactionSequenceNumber=0;
    switch(recieveTransactionData(&Loc_tTransaction))
	{
		case APPROVED:
			printf("APPROVED\n");
			break;
		case DECLINED_INSUFFECIENT_FUND:
			printf("amount is not available\n");
			break;
		case DECLINED_STOLEN_CARD:
			printf("Blocked account\n");
			break;
		case FRAUD_CARD:
			printf("account does not exist");
			break;
	}
}