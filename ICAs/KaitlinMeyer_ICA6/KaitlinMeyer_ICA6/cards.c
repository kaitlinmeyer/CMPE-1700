#include "cards.h"
#include <string.h>

/*
Name: Kaitlin Meyer
Assignment: ICA 06
Class: CMPE 1700
Instructor: Oveeyn Moonian
*/



//functions
void GetName(cardSuit cS, cardValue cV, Card* C, char Suit[20], char Value[20]);

void main() {

	//variables
	cardSuit cS = 0;
	cardValue cV = 2;
	Card deckCards[52];
	char strSuit[20];
	char strValue[20];
	int index = 0;


	for (int suit = 0; suit < 4; suit++)

	{
		cS = suit;

		for (int value = 2; value < 15; value++)
		{
			cV = value;
			GetName(cS, cV, &deckCards[index], strSuit, strValue);
			index++;
		}

	}

	exit(EXIT_SUCCESS);
}

void GetName(cardSuit cS, cardValue cV, Card* C, char Suit[20], char Val[20])
{
	C->suit = cS;
	C->val = cV;

	//cases for card suit
	switch (cS)
	{
	case Clubs: Suit = "Clubs";
		break;
	case Diamonds: Suit = "Diamonds";
		break;
	case Hearts: Suit = "Hearts";
		break;
	case Spades: Suit = "Spades";
		break;
	default:

		//error message
		printf("Error: no card suit.\n");
	}

	//cases for card value
	switch (cV)
	{
	case Deuce: Val = "Deuce";
		break;
	case Three: Val = "Three";
		break;
	case Four: Val = "Four";
		break;
	case Five: Val = "Five";
		break;
	case Six: Val = "Six";
		break;
	case Seven: Val = "Seven";
		break;
	case Eight: Val = "Eight";
		break;
	case Nine: Val = "Nine";
		break;
	case Ten:  Val = "Ten";
		break;
	case Jack: Val = "Jack";
		break;
	case Queen: Val = "Queen";
		break;
	case King: Val = "King";
		break;
	case Ace:  Val = "Ace";
		break;
	default:
		//error message
		printf("Error: no card value.\n");
	}


	printf("%-7s of  %-10s \n", Val, Suit);
}
