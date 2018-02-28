#include <iostream>

#include "Enemy.h"
#include "Werewolf.h"
#include "Human.h"

int main()
{
	const int MAX_BADDIES = 10;

	Enemy * baddies [MAX_BADDIES];

	baddies[0] = new Werewolf("Ror", 35, 200, 180, 5);     
	baddies[1] = new Werewolf("Bor", 25, 200, 180, 3);     
	baddies[2] = new Werewolf("Tor", 45, 200, 180, 4);     
	baddies[3] = new Werewolf("Gor", 15, 200, 180, 8);     
	baddies[4] = new Werewolf("Mor", 33, 200, 180, 6);

	baddies[5] = new Human("Joe", 10, 50, 110, 15);     
	baddies[6] = new Human("Jim", 11, 50, 110, 11);
	baddies[7] = new Human("Snake", 12, 50, 110, 12);     
	baddies[8] = new Human("Luke", 9, 50, 110, 13);     
	baddies[9] = new Human("Duke", 8, 50, 110, 13);

	for (int i = 0; i < MAX_BADDIES; i++)
	{
		std::cout << baddies[i]->GetName();
		std::cout << "'s type is: "; 
		baddies[i]->Type();
	}

	for (int i = 0; i < MAX_BADDIES; i++)
	{
		delete baddies[i];
		baddies[i] = 0;
	}

	int wait;
	std::cin >> wait;

	return 0;
}