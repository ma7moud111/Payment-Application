#include <stdio.h>
#include <string.h>
#include"terminal.h"
#include "../payment application/card.h"

/*this function asks for transaction date and store it in the terminal data*/
EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	printf("Enter transaction date:\n");
	termData = (ST_terminalData_t*)malloc(1 * sizeof(ST_terminalData_t));
	gets(termData->transactionDate);
	int length = strlen(termData->transactionDate);
	if (termData->transactionDate == NULL || length < 10)
	{
		return WRONG_DATE;
	}
	else
	{
		if ((termData->transactionDate[0] >= '0' && termData->transactionDate[0] <= '3') && (termData->transactionDate[1] >= '0' && termData->transactionDate[1] <= '9') && (termData->transactionDate[2] == '/') && (termData->transactionDate[3] >= '0' && termData->transactionDate[3] <= '1') && (termData->transactionDate[4] >= '0' && termData->transactionDate[4] <= '2') && termData->transactionDate[5] == '/')
		{
			return TERMINAL_OK;
		}
		else
		{
			return WRONG_DATE;
		}
	}
}

/*this function is to ensure that the transaction date is before the expiration date*/
EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData)
{
	if (cardData->cardExpirationDate[2] > termData->transactionDate[8]) {
		return TERMINAL_OK;
	}
	else {
		if (cardData->cardExpirationDate[2] == termData->transactionDate[8] && cardData->cardExpirationDate[3] > termData->transactionDate[9]) {
			return TERMINAL_OK;
		}
		else {
			return EXPIRED_CARD;
		}
	}
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	printf("Enter Transaction Amount: ");
	termData = (ST_terminalData_t*)malloc(1 * sizeof(ST_terminalData_t));
	scanf_s("%f", &termData->transAmount);
	if (termData->transAmount <= 0) {
		return INVALID_AMOUNT;
	}
	else {
		return TERMINAL_OK;
	}
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	
	if (termData->transAmount <= termData->maxTransAmount) {
		return TERMINAL_OK;
	}
	else {
		return EXCEED_MAX_AMOUNT;
	}
}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount)
{
	termData = (ST_terminalData_t*)malloc(1 * sizeof(ST_terminalData_t));
	termData->maxTransAmount = maxAmount;
	if (maxAmount <= 0) {
		return INVALID_MAX_AMOUNT;
	}
	else {
		return TERMINAL_OK;
	}
}

EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData)	// Optional
{

}



	


