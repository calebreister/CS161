#include "CardSuperFun.h"

int main()
{
	int deck[deck::SIZE];
	deck::init(deck);
	cout << "Ordered deck" << endl;
	deck::dump(deck, deck::SIZE);//print non-random deck
	deck::shuffle(deck, deck::SIZE);
	cout << endl << "Shuffled deck" << endl;
	deck::dump(deck, deck::SIZE);//print shuffled deck
	cout << endl << endl;
	//testing card::print with all situations
	//testing card::HandPrint
	//NOTE: card::HandPrint calls card::print
	int TestHand[] = {301 ,310, 411, 512, 613, 600};
	cout << "HandPrint" << endl;
	card::HandPrint(TestHand, 5);
	cout << endl << "HandPrint hiding 1st card" << endl;
	card::HandPrint(TestHand, 5, true);

	cin.get();
	cin.ignore();
}

void deck::init(int deck[])
{
	int index;
	int card = 0;// used as the card number because index cannot be reset
	for (index = 0; index < 13; index++)
	{
		deck[index] = card + 1 + 300;//sets value to index and sets suit to heart
		//the +1 offsets the fact that index starts at 0, giving Ace a value of 1
		card++;
	}
	card = 0;
	for (index; index < 26; index++)//26 gets to end of suit
	{
		deck[index] = card + 1 + 400;
		card++;
	}
	card = 0;
	for (index; index < 39; index++)
	{
		deck[index] = card + 1 + 500;
		card++;
	}
	card = 0;
	for (index; index < 52; index++)
	{
		deck[index] = card + 1 + 600;
		card++;
	}
}

void deck::dump(const int deck[], int size)
{
	for (int index = 0; index < size; index++)
		cout << deck[index] << endl;
}

void deck::shuffle(int deck[], int size)
{
	for (int rep = 0; rep < 5; rep++)//number of times to repeat the shuffling
	{
		for (int count = 0; count < size; count++)
		{
			int Card1 = deck[count];
			int index = RandNum(0, 51);
			int Card2 = deck[index];
			deck[index] = Card1;
			deck[count] = Card2;
		}
	}
}

void card::print(int card)
{
	char suit = card / 100;
	int num = card % 100;
	switch (num)
	{
		case 13://King
			cout << 'K' << suit;
			break;
		case 12://Queen
			cout << 'Q' << suit;
			break;
		case 11://Jack
			cout << 'J' << suit;
			break;
		case 1://Ace
			cout << 'A' << suit;
			break;
		default:
			cout << num << suit;
	}
}

void card::HandPrint(const int cards[], int CardCount, bool HideTopCard)
{
	int index = 0;
	if (HideTopCard == true)
	{
		cout << "X ";//placeholder for hidden card
		index = 1;
	}
	for (index; index < CardCount; index++)
	{
		if (cards[index] == 0)//skip cards that do not exist in the hand
			//example: the hand is smaller than the array
			continue;
		card::print(cards[index]);
		cout << ' ';
	}
}

int RandNum(int low, int high)
{
	static bool firstTime=true;
	int randNum;
	//if first time called, seed random number generator
	if (firstTime) 
	{
		srand( static_cast<unsigned int>(time(NULL)) );
		firstTime=false;
	}
	//generate random number between given low and high values (inclusive)
	randNum = rand() % (high-low+1) + low;
	return randNum;
}