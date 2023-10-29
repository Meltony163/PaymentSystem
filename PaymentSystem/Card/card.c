#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"../../Libraries/cardlibrary.h"
EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
{
    char *Loc_cPtr,Loc;
    Loc_cPtr=(char*)malloc(50*sizeof(char));
    scanf("%[^\n]%*c",Loc_cPtr);
    if((strlen(Loc_cPtr)>=20)&&((strlen(Loc_cPtr)<25)))
    {
        int i=0;
        while(Loc_cPtr[i])
        {
            (cardData->cardHolderName)[i]=Loc_cPtr[i];
            i++;
        }
        (cardData->cardHolderName)[i]='\0';
        free(Loc_cPtr);
        return CARD_OK;
    }
    free(Loc_cPtr);
    return WRONG_NAME;
}

EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
{
    char *Loc_cPtr;
    Loc_cPtr=(char*)malloc(10*sizeof(char));
    scanf("%[^\n]%*c",Loc_cPtr);
    if(strlen(Loc_cPtr)==5)
    {
        if((Loc_cPtr[0]=='0')||(((Loc_cPtr[0]=='1'))&&(Loc_cPtr[1]<='2')&&(Loc_cPtr[1]>='0')))
        {
            if(Loc_cPtr[2]!='/')
            {
                free(Loc_cPtr);
                return WRONG_EXP_DATE;
            }
            if((Loc_cPtr[3]>='0')&&(Loc_cPtr[3]<='9'))
            {
                if((Loc_cPtr[4]>='0')&&(Loc_cPtr[4]<='9'))
                {
                    int i=0;
                    while(Loc_cPtr[i])
                    {
                        (cardData->cardExpirationDate)[i]=Loc_cPtr[i];
                        i++;
                    }
                    (cardData->cardExpirationDate)[i]='\0';
                    free(Loc_cPtr);
                    return CARD_OK;
                }
            }
            free(Loc_cPtr);
            return WRONG_EXP_DATE;
        }
        free(Loc_cPtr);
        return WRONG_EXP_DATE;
    }
    free(Loc_cPtr);
    return WRONG_EXP_DATE;
}

EN_cardError_t getCardPAN(ST_cardData_t *cardData)
{
    char *Loc_cPtr;
    Loc_cPtr=(char*)malloc(30*sizeof(char));
    scanf("%[^\n]%*c",Loc_cPtr);
    if((strlen(Loc_cPtr)>=16)&&(strlen(Loc_cPtr)<20))
    {
        int i=0;
        while(Loc_cPtr[i])
        {
            if((Loc_cPtr[i]>='0')&&(Loc_cPtr[i]<='9'))
            {
              i++;
              continue;
            }
            free(Loc_cPtr);
            return WRONG_PAN;
        }
        i=0;
        while(Loc_cPtr[i])
        {
            (cardData->primaryAccountNumber)[i]=Loc_cPtr[i];
            i++;
        }
        (cardData->primaryAccountNumber)[i]='\0';
        free(Loc_cPtr);
        return CARD_OK;
    }
    free(Loc_cPtr);
    return WRONG_PAN;
}
