#include"../../Libraries/terminallibrary.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../../Libraries/cardlibrary.h"
EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
{
    char *Loc_cPtr;
    Loc_cPtr=(char*)malloc(20*sizeof(char));
    scanf("%[^\n]%*c",Loc_cPtr);
    if(strlen(Loc_cPtr)==10)
    {
        if((Loc_cPtr[2]=='/')&&(Loc_cPtr[5]=='/'))
        {
            if((Loc_cPtr[0]>'3')||((Loc_cPtr[0]=='3')&&(Loc_cPtr[1]>'1')))
            {
                free(Loc_cPtr);
                return WRONG_DATE;
            }
            if((Loc_cPtr[3]>'2')||((Loc_cPtr[3]=='1')&&(Loc_cPtr[4]>'2')))
            {
                free(Loc_cPtr);
                return WRONG_DATE;
            }
            int i=0;
            while(Loc_cPtr[i])
            {
                if((i==2)||(i==5))
                {
                    i++;
                    continue;
                }
                if(!((Loc_cPtr[i]>='0')&&(Loc_cPtr[i]<='9')))
                {
                    free(Loc_cPtr);
                    return WRONG_DATE;
                }
                i++;
            }
            i=0;
            while(Loc_cPtr[i])
            {
                (termData->transactionDate)[i]=Loc_cPtr[i];
                i++;
            }
            (termData->transactionDate)[i]='\0';
            free(Loc_cPtr);
            return TERMINAL_OK;
        }
        free(Loc_cPtr);
        return WRONG_DATE;
    }
    free(Loc_cPtr);
    return WRONG_DATE;
}

EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t* termData)
{
    int Loc_nCard=0,Loc_nTerm=0;
    for(int i=8;i<10;i++)
    {
        Loc_nTerm=Loc_nTerm*10;
        Loc_nTerm=Loc_nTerm+(int)((termData->transactionDate)[i]-'0');
    }
    for(int i=3;i<5;i++)
    {
        Loc_nCard=Loc_nCard*10;
        Loc_nCard=Loc_nCard+(int)((cardData->cardExpirationDate)[i]-'0');
    }
    if(Loc_nTerm>Loc_nCard)
    {
        return EXPIRED_CARD;
    }
    else if(Loc_nTerm<Loc_nCard)
    {
        return TERMINAL_OK;
    }
    Loc_nCard=0;
    Loc_nTerm=0;
    for(int i=3;i<5;i++)
    {
        Loc_nTerm=Loc_nTerm*10;
        Loc_nTerm=Loc_nTerm+(int)((termData->transactionDate)[i]-'0');
    }
    for(int i=0;i<2;i++)
    {
        Loc_nCard=Loc_nCard*10;
        Loc_nCard=Loc_nCard+(int)((cardData->cardExpirationDate)[i]-'0');
    }
    if(Loc_nTerm>Loc_nCard)
    {
        return EXPIRED_CARD;
    }
    return TERMINAL_OK;
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
{
    float Loc_fData;
    scanf("%f",&Loc_fData);
    if(Loc_fData<=0)
    {
        return INVALID_AMOUNT;
    }
    termData->transAmount=Loc_fData;
    return TERMINAL_OK;
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
{
    if((termData->transAmount)>(termData->maxTransAmount))
    {
        return EXCEED_MAX_AMOUNT;
    }
    return TERMINAL_OK;
}

EN_terminalError_t setMaxAmount(ST_terminalData_t *termData, float maxAmount)
{
    if(maxAmount<=0)
    {
        return INVALID_MAX_AMOUNT;
    }
    termData->maxTransAmount=maxAmount;
    return TERMINAL_OK;
}