//includes
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

//include .h file
#include "ItemChoices.h"

//declare array
int arr[3] = { 0, 1, 2 };
int nextAttackMod = 0;

//itemChoices function that takes the references of playerHealth and playerMana
int itemChoices(int& playerHealth, int& playerMana)
{
	//declare variables

	int playerItem;
	int playerCheck = 2;

	//check for player to say they're sure about their decision
	while (playerCheck == 2)
	{
		//text output and for loops to determine which items are displayed based on if they've been used or not
		std::cout << "\nWhich item would you like to use?\n\n";
		std::cout << std::setw(50) << std::right << "Items:" << std::endl;
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

		//player input to give player a chance to choose something else
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
	//switch to determine which item gets consumed
	switch (playerItem)
	{
	case 1:
		//set arr[0] to 8 so that it will no longer print in for loops, give player 50 health but no more than 100, return nextAttackMod
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
			return nextAttackMod;
		}
		else
		{
			//return to main menu if item has already been consumed
			std::cout << "\nYou've already consumed this item.\n";
			battle();
		}
		break;
	case 2:
		//set arr[1] to 8 so that it will no longer print in for loops, give player 30 mana but no more than 100, return nextAttackMod
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
			return nextAttackMod;
		}
		else {
			//return to main menu if item has already been consumed
			std::cout << "\nYou've already consumed this item.\n";
			battle();
		}
		break;
	case 3:
		//set arr[2] to 8 so that it will no longer print in for loops, set nextAttackMod to 30, return nextAttackMod
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
			return nextAttackMod;
		}
		else
		{
			//return to main menu if item has already been consumed
			std::cout << "\nYou've already consumed this item.\n";
			battle();
		}
		break;
	case 4:
		//print item descriptions
		std::cout << "\nHealth Potion: Consume to gain back 30 health." << std::endl;
		std::cout << "\nMana Elixir: Consume to gain back 30 mana." << std::endl;
		std::cout << "\nBerserker Beer: Consume to gain significantly more attack damage for a turn.\n" << std::endl;
		system("pause");
		battle();
		break;
	default:
		//send player back to main menu
		battle();
		break;
	}
}