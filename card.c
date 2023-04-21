#include <stdio.h>
#include <stdlib.h>
#include "card.h"

EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	cardData = (ST_cardData_t*)malloc(1*sizeof(ST_cardData_t));
	printf("Card Holder Name: ");
	gets(cardData->cardHolderName);
	int length = strlen(cardData->cardHolderName);
	if (cardData->cardHolderName[0] == '\0' || length > 23 || length < 20) {
		return WRONG_NAME;
	}
	else {
		return CARD_OK;
	}
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	cardData = (ST_cardData_t*)malloc(1 * sizeof(ST_cardData_t));
	printf("Card Expiration Date:  ");
	gets(cardData->cardExpirationDate);
	int length = strlen(cardData->cardExpirationDate);
	int f = 0;
	if ((cardData->cardExpirationDate[0] < '0' || cardData->cardExpirationDate[0] > '1' || cardData->cardExpirationDate[1] < '0' || cardData->cardExpirationDate[1] > '2') || cardData->cardExpirationDate[2] != '/' || cardData->cardExpirationDate[3] < '0' || cardData->cardExpirationDate[3] > '9' || cardData->cardExpirationDate[4] < '0' || cardData->cardExpirationDate[4] > '9')
	{
		f = 1;
	}
	if (!(cardData->cardExpirationDate[0] == '\0' || length != 5 || f))
	{
		
		return CARD_OK;
	}
	else
	{
		if ((cardData->cardExpirationDate[0] == '0' && cardData->cardExpirationDate[1] <= '9'))
		{
			return CARD_OK;
		}
		return WRONG_EXP_DATE;
	}
}

EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	cardData = (ST_cardData_t*)malloc(1 * sizeof(ST_cardData_t));
	printf("Primary Account Number: ");
	gets(cardData->primaryAccountNumber);
	int f = 0, length = strlen(cardData->primaryAccountNumber);
	for (int i = 0; i < length; i++) {
		if (cardData->primaryAccountNumber[i] < '0' || cardData->primaryAccountNumber[i] > '9')
		{
			f = 1;
			break;
		}
	}

	if (length > 19 || length < 16 || f)
	{
		return WRONG_PAN;
	}
	else
	{
		return CARD_OK;
	}
}