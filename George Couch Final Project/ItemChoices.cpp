#include <iostream>
#include <iomanip>
#include "ItemChoices.h"

int arr[3] = { 0, 1, 2 };

int itemChoices(int& playerHealth, int& playerMana)
{
	int nextAttackMod = 0;
	int options = 1;
	int playerItem;
	while (options == 1)
	{
		int playerCheck = 2;
		while (playerCheck == 2)
		{
			//Use item
			std::cout << "\nWhich item would you like to use?\n\n";
			//for loop to display items
			for (int i = 0; i < 3; i++) {
				if (i == arr[i]) {
					switch (i)
					{
					case 0:
						std::cout << "Health Potion\n";
						break;
					case 1:
						std::cout << "Mana Elixir\n";
						break;
					case 2:
						std::cout << "Berserker Beer\n";
					default:
						break;
					}
				}
			}
			//std::cout << std::setw(50) << std::right << "Items:" << std::endl;
			//std::cout << std::setw(22) << std::right << "(1)" << std::setw(20) << "(2)" << std::setw(18) << "(3)" << std::setw(20) << "(4)" << std::endl;
			//std::cout << std::setw(22) << std::right << "\tHealth Potion" << std::setw(18) << "Mana Elixir" << std::setw(20) << "Berserker Beer" << std::setw(20) << "Item Descriptions" << std::endl;
			std::cout << "\nEnter 5 to go back to main menu.";
			std::cin >> playerItem;
			if (playerItem >= 1 && playerItem <= 3) 
			{
				std::cout << "Are you sure you want to cast this spell?";
				std::cout << "(1) Yes, (2) No";
				std::cin >> playerCheck;
			}
			else
			{
				playerCheck = 1;
			}
		}
		switch (playerItem)
		{
		case 1:
			if (arr[0] == 0) {
				arr[0] = 8;
				// Consume Health Potion
				playerHealth += 30;
				if (playerHealth > 100) {
					playerHealth = 100;
				}
				options = 0;
				return nextAttackMod;
			}
			else
			{
				std::cout << "You've already consumed this potion";
			}
			break;
		case 2:
			if (arr[1] == 1) {
				arr[1] = 8;
				// Consume Mana Elixir
				playerMana += 30;
				if (playerMana > 100) {
					playerMana = 100;
				}
				options = 0;
				return nextAttackMod;
			}
			else {
				std::cout << "You've already consumed this potion";
			}
			break;
		case 3:
			if (arr[2] == 2) {
				arr[2] = 8;
				// Consume Berserker Beer
				nextAttackMod = 30;
				options = 0;
				return nextAttackMod;
			}
			else
			{
				std::cout << "You've already consumed this potion";
			}
			break;
		case 4:
			std::cout << "\nHealth Potion: Consume to gain back 30 health." << std::endl;
			std::cout << "\nMana Elixir: Consume to gain back 30 mana." << std::endl;
			std::cout << "\nBerserker Beer: Consume to gain significantly more attack damage fo a turn.\n" << std::endl;
			system("pause");
			break;
		default:
			battle();
			break;
		}
	}
}