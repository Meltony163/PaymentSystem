#ifndef SERVER
#define SERVER
#include"../../Libraries/terminallibrary.h"
#include"../../Libraries/cardlibrary.h"
#include"../../Libraries/serverlibrary.h"

EN_transStat_t recieveTransactionData(ST_transaction *transData);

EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t* accountRefrence);

EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence);

EN_serverError_t isAmountAvailable(ST_terminalData_t *termData,ST_accountsDB_t* accountRefrence);

EN_serverError_t saveTransaction(ST_transaction *transData);

void listSavedTransactions(void);

#endif