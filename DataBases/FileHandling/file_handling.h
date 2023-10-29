#ifndef FILE_h
#define FILE_h
#include"../../Libraries/terminallibrary.h"
#include"../../Libraries/serverlibrary.h"
#include"../../Libraries/cardlibrary.h"
#include<stdio.h>
#include <stdint.h>

void FILH_vSaveAccounts();

void FILH_vAddAccount(ST_accountsDB_t* ptr_aAccount);

void FILH_vAddTransaction(ST_transaction* ptr_tTransaction);

void FILH_vDeleteAllAccounts();

void FILH_vDeleteAllTransaction();

int FILH_vReadAccounts(ST_accountsDB_t** ptr_pAccount);

void FILH_vReadAllTransactions();

#endif