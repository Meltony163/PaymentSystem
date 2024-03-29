#ifndef TERMINAL
#define TERMINAL
#include"../../Libraries/terminallibrary.h"

EN_terminalError_t getTransactionDate(ST_terminalData_t *termData);

EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t* termData);

EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData);

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData);

EN_terminalError_t setMaxAmount(ST_terminalData_t *termData, float maxAmount);

#endif