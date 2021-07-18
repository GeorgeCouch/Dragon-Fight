#include <iostream>
#include <iomanip>
#include "ItemChoices.h"
#include <chrono>
#include <thread>

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
			std::cout << std::setw(50) << std::right << "Items:" << std::endl;
			//std::cout << std::setw(22) << std::right << "(1)" << std::setw(20) << "(2)" << std::setw(18) << "(3)" << std::setw(20) << "(4)" << std::endl;
			//for loop to display items
			for (int i = 0; i < 3; i++) {
				if (i == arr[i]) {
					switch (i)
					{
					case 0:
						std::cout << std::setw(22) << "(1)";
						break;
					case 1:
						std::cout << std::setw(18) << "(2)";
						break;
					case 2:
						std::cout << std::setw(20) << "(3)";
					default:
						break;
					}
				}
			}
			std::cout << std::setw(20) << "(4)" << std::setw(15) << "(5)";
			std::cout << "\n";
			for (int i = 0; i < 3; i++) {
				if (i == arr[i]) {
					switch (i)
					{
					case 0:
						std::cout << std::setw(22) << "Health Potion";
						break;
					case 1:
						std::cout << std::setw(18) << "Mana Elixir";
						break;
					case 2:
						std::cout << std::setw(20) << "Berserker Beer";
					default:
						break;
					}
				}
			}
			std::cout << std::setw(20) << "Item Descriptions" << std::setw(15) << "Main Menu" << std::endl;
			//std::cout << std::setw(22) << std::right << "\tHealth Potion" << std::setw(18) << "Mana Elixir" << std::setw(20) << "Berserker Beer" << std::setw(20) << "Item Descriptions" << std::endl;
			//std::cout << "\nEnter 5 to go back to main menu.";
			std::cin >> playerItem;
			if (playerItem >= 1 && playerItem <= 3) 
			{
				std::cout << "\nAre you sure you want to use this item?\n\n";
				std::cout << std::setw(55) << std::right << "(1) Yes, (2) No\n";
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
				std::cout << "\nYou consume a health potion";
				for (int i = 0; i < 3; i++) {
					std::chrono::milliseconds timespan(500);
					std::cout << ".";
					std::this_thread::sleep_for(timespan);
				}
				playerHealth += 50;
				if (playerHealth > 100) {
					playerHealth = 100;
				}
				std::cout << "\nYou gained 50 health!";
				std::cout << "\nYour Health: " << playerHealth << std::endl;
				options = 0;
				return nextAttackMod;
			}
			else
			{
				std::cout << "You've already consumed this item.";
			}
			break;
		case 2:
			if (arr[1] == 1) {
				arr[1] = 8;
				// Consume Mana Elixir
				std::cout << "\nYou consume a mana elixir";
				for (int i = 0; i < 3; i++) {
					std::chrono::milliseconds timespan(500);
					std::cout << ".";
					std::this_thread::sleep_for(timespan);
				}
				playerMana += 30;
				if (playerMana > 100) {
					playerMana = 100;
				}
				std::cout << "\nYou gained 30 mana!";
				std::cout << "\nYour Mana: " << playerMana << std::endl;
				options = 0;
				return nextAttackMod;
			}
			else {
				std::cout << "You've already consumed this item.";
			}
			break;
		case 3:
			if (arr[2] == 2) {
				arr[2] = 8;
				// Consume Berserker Beer
				std::cout << "\nYou consume a berserker beer";
				for (int i = 0; i < 3; i++) {
					std::chrono::milliseconds timespan(500);
					std::cout << ".";
					std::this_thread::sleep_for(timespan);
				}
				nextAttackMod = 30;
				std::cout << "\nYour next attack will be stronger than usual!" << std::endl;
				options = 0;
				return nextAttackMod;
			}
			else
			{
				std::cout << "You've already consumed this item.";
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