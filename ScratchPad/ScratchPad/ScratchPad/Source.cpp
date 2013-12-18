#include <iostream>
using namespace std;
int CountCards(int deck[], int size)
{
	int CardCount = 0;
	for(int index = 0; index < size; index++)
	{
		if (deck[index] != 0)
			CardCount++;
	}
	return CardCount;
}

int main()
{
	int deck[6] = {1,2,3,0,5,6};
	cout << CountCards(deck, 6);
	cin.get();
}