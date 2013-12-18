/*
PROGRAM: CardSuperFun
AUTHOR: Caleb Reister
DATE: 2013-11-27
DEV ENV: MS VisualStudio 2012
DESCRIPTION: First program in group of 2 to implement a
	console version of blackjack.
	Main purpose: create the card managing functions for 21
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
Card indexing key:
	- rank will be A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, or K
	- suit will be displayed using the ASCII character
		values 3 (heart), 4 (diamond), 5 (club), 6 (spade)
	- takes a 3 digit number denoting the suit and card number
	- 1st digit is the ASCII value of the suit
	- Last 2 digits are the number of card
	- 305 = 3 of hearts
	- 512 = Jack of clubs
*/

namespace deck//namespace for deck management
{
	const int SIZE = 52;
	/*
	FUNCTION: DeckInit
	DESCRIPTION: Initializes a "deck" of 52 cards to the correct numbers
		and suits
	PARAMETERS:
		-I/O deck[]: an int array that will serve as the deck of cards
	RETURN VALUES: none
	*/
	void init(int deck[]);
	/*========================================
	FUNCTION: DeckDump
	DESCRIPTION: displays the given deck as integers one per line
		Only used for testing purposes
	PARAMETERS:
		-I deck[]: the deck of cards to display
		-I size: the size of the card deck
	RETURN VALUES: prints deck of cards
	*/
	void dump(const int deck[], int size);
	/*========================================
	FUNCTION: DeckShuffle
	DESCRIPTION: Randomize a deck of cards (in an array)
	PARAMETERS:
		-I/O deck[]: the deck of cards to shuffle
		-I size: the number of cards to shuffle
	RETURN VALUES: randomized deck of cards
	*/
	void shuffle(int deck[], int size);
}

namespace card// namespace for card management
{
	/*
	FUNCTION: CardPrint
	DESCRIPTION: displays the given card’s rank and suit
	PARAMETERS:
		-I card: the card value to print
	RETURN VALUES: prints the card and suit character
	*/
	void print(int card);
	/*========================================
	FUNCTION: CardHandPrint
	DESCRIPTION: prints an array of cards with the option to hide the first,
		uses the same numbering system as CardPrint()
	PARAMETERS:
		-I cards[]: the cards to print
		-I CardCount: number of cards to print
		-I HideTopCard: option to hide the top card (for the dealer in 21)
	RETURN VALUES: prints cards
	*/
	void HandPrint(const int cards[], int CardCount, bool HideTopCard = false);
}

/*========================================
FUNCTION: RandNum
DESCRIPTION: Returns a psuedo-random number between given
	low and high, values, inclusive
PARAMETERS:
	-I low: the lowest number to be generatred
	-I high: the highest number to be generated
RETURN VALUES: A psuedo-random number between low and high (inclusive)
*/
int RandNum(int low, int high);