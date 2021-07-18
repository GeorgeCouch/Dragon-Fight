//Allows for input and output
#include <iostream>
//Allows for user input
#include <string>
//Allows for time waiting
#include <thread>
#include <chrono>
//Allows for cout formatting
#include <iomanip>

#include "DragonAbility.h"
#include "Spells.h"
#include "ItemChoices.h"

int castPlayerSpell(int* totalMana);
int playerAttack();
int playerDefend();
int itemChoices(int& playerHealth, int& playerMana);
void introduction();
void battle();

int dragonHealth = 100;
int playerHealth = 100;
int playerMana = 100;
int playerSpell;
int chargeAttack = 1;
int randNum;
int playerChoice;
int defend = 0;
int playerItem;
int options = 1;
int nextAttack = 0;
int nextSpellAttack = 0;
int dragonValue = 1;
int nextAttackMod = 0;
int dragonDamage;
int* totalMana = &playerMana;
std::string name = "";

//main
int main()
{
	introduction();
	std::cout << "\nDragon's Health: " << dragonHealth;
	std::cout << "\nYour Health: " << playerHealth;
	std::cout << "\nYour Mana: " << playerMana << std::endl;
	std::cout << "\n";
	system("pause");
	std::cout << "\n";
	battle();
	if (playerHealth <= 0) {
		std::cout << "\n\nYou were defeated by the dragon.\n\n\n";
	}
	else {
		std::cout << "\n\nCongragulations " << name << ", you defeated the dragon!\n\n\n";
	}
}

void introduction()
{
	//Description of what the program does
	std::cout << "\n\n\t***Save us from the dragon!***\n";
	std::cout << "\nRules:";
	std::cout << "\n-Defeat the dragon before it defeats you.";
	std::cout << "\n-Manage your mana when casting spells.";
	std::cout << "\n-Consume items to obtain more power.\n";
	//ask the user for their name
	std::cout << "\nWhat is your name adventurer?\n";
	std::cout << "\nName: ";
	getline(std::cin, name);
	std::cout << "\n";
	//Greet by name
	std::cout << name + ", good luck in your battle...";
	std::cout << "\n\nThe fight is beginning";
	for (int i = 0; i < 3; i++) {
		std::chrono::milliseconds timespan(500);
		std::cout << ".";
		std::this_thread::sleep_for(timespan);
	}
	std::cout << "\n";
}

void battle() {
	while (dragonHealth > 0 && playerHealth > 0)
	{
		int playerCheck = 2;
		while (playerCheck == 2)
		{
			std::cout << "\nWhat would you like to do?\n" << std::endl;
			std::cout << std::setw(20) << std::right << "(1)" << std::setw(20) << "(2)" << std::setw(20) << "(3)" << std::setw(21) << "(4)" << std::endl;
			std::cout << std::setw(21) << std::right << "Attack" << std::setw(20) << "Magic" << std::setw(20) << "Defend" << std::setw(20) << "Item" << std::endl;
			std::cin >> playerChoice;
			if (playerChoice == 1 || playerChoice == 3)
			{
				std::cout << "\nAre you sure you want to do this action?\n\n";
				std::cout << std::setw(55) << std::right << "(1) Yes, (2) No\n";
				std::cin >> playerCheck;
			}
			else
			{
				playerCheck = 1;
			}
		}
		switch (playerChoice)
		{
		case 1:
			nextAttack = playerAttack();
			break;
		case 2:
			nextSpellAttack = castPlayerSpell(&playerMana);
			break;
		case 3:
			defend = playerDefend();
			break;
		case 4:
			nextAttackMod = itemChoices(playerHealth, playerMana);
			break;
		default:
			break;
		}

		if (nextAttack != 0 && nextAttackMod == 0) {
			dragonDamage = nextAttack;
			std::cout << "You dealt " << dragonDamage << " damage!" << std::endl;
			nextAttack = 0;
			dragonHealth -= dragonDamage;
		}
		else if (nextAttack != 0 && nextAttackMod != 0) {
			std::cout << "Base Attack: " << nextAttack << std::endl;
			std::cout << "Berserker Beer: " << nextAttackMod << std::endl;
			dragonDamage = nextAttack + nextAttackMod;
			std::cout << "You dealt " << dragonDamage << " damage!" << std::endl;
			nextAttack = 0;
			nextAttackMod = 0;
			dragonHealth -= dragonDamage;
		}
		else if (nextSpellAttack != 0) {
			dragonDamage = nextSpellAttack;
			nextSpellAttack = 0;
			dragonHealth -= dragonDamage;
		}

		std::cout << "\n";
		system("pause");

		if (dragonHealth <= 0) {
			continue;
		}

		if (dragonValue >= 1)
		{
			dragonValue = dragonAbility(dragonValue);
		}
		else
		{
			dragonValue = dragonAbility(dragonValue);
		}
		if (defend == 1)
		{
			dragonValue /= 2;
			//std::cout << "Dragon damage after defend: " << dragonValue << std::endl;
			playerHealth -= dragonValue;
			defend = 0;
		}
		else if (defend == 0)
		{
			//std::cout << "Dragon dealing normal damage\n";
			playerHealth -= dragonValue;
		}
		if (defend == 1)
		{
			std::cout << "You lower your shield...\n";
			defend = 0;
		}

		std::cout << "\nDragon's Health: " << dragonHealth;
		std::cout << "\nYour Health: " << playerHealth;
		std::cout << "\nYour Mana: " << playerMana << std::endl;
	}
}

int playerDefend()
{
	//Defend
	std::cout << "\nYou raise your shield and prepare for the dragon's next attack";
	for (int i = 0; i < 3; i++) {
		std::chrono::milliseconds timespan(500);
		std::cout << ".";
		std::this_thread::sleep_for(timespan);
	}
	defend = 1;
	std::cout << "\nYour defense will cause the dragon's next attack to do half of its damage to you!";
	std::cout << "\n";
	return defend;
}

int playerAttack()
{
	//Attack
	std::cout << "\nYou swing your sword at the dragon";
	for (int i = 0; i < 3; i++) {
		std::chrono::milliseconds timespan(500);
		std::cout << ".";
		std::this_thread::sleep_for(timespan);
	}
	srand(time(0));
	randNum = rand() % 10 + 3;//range between 3 and 10;
	std::cout << "\n";
	return randNum;
}