#include <iostream>
#include <iomanip>
#include "ItemChoices.h"
int itemChoices(int& playerHealth, int& playerMana)
{
	int nextAttackMod = 0;
	int options = 1;
	int playerItem;
	while (options == 1)
	{
		//Use item
		std::cout << "\nWhich item would you like to use?\n\n";
		std::cout << std::setw(50) << std::right << "Items:" << std::endl;
		std::cout << std::setw(22) << std::right << "(1)" << std::setw(20) << "(2)" << std::setw(18) << "(3)" << std::setw(20) << "(4)" << std::endl;
		std::cout << std::setw(22) << std::right << "\tHealth Potion" << std::setw(18) << "Mana Elixir" << std::setw(20) << "Berserker Beer" << std::setw(20) << "Item Descriptions" << std::endl;
		std::cin >> playerItem;
		switch (playerItem)
		{
		case 1:
			// Consume Health Potion
			playerHealth += 30;
			if (playerHealth > 100) {
				playerHealth = 100;
			}
			options = 0;
			return nextAttackMod;
			break;
		case 2:
			// Consume Mana Elixir
			playerMana += 30;
			if (playerMana > 100) {
				playerMana = 100;
			}
			options = 0;
			return nextAttackMod;
			break;
		case 3:
			// Consume Berserker Beer
			nextAttackMod = 30;
			options = 0;
			return nextAttackMod;
			break;
		case 4:
			std::cout << "\nHealth Potion: Consume to gain back 30 health." << std::endl;
			std::cout << "\nMana Elixir: Consume to gain back 30 mana." << std::endl;
			std::cout << "\nBerserker Beer: Consume to gain significantly more attack damage fo a turn.\n" << std::endl;
			system("pause");
			break;
		default:
			break;
		}
	}
}