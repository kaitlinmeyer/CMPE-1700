#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//enumuration for card suits
enum cardSuit { Clubs, Diamonds, Hearts, Spades };
typedef enum cardSuit cardSuit;

//enumeration for value of card
enum cardValue
{ Deuce = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

typedef enum cardValue cardValue;

//structure for card suit and card value
struct Card
{
    cardSuit suit;
    cardValue val;
};
typedef struct Card Card;

//function GetName
void GetName(cardSuit cS, cardValue cV, Card* C, char Suit[20], char Val[20]);