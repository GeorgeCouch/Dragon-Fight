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

int dragonHealth = 100;
int playerHealth = 40;
int playerMana = 50;
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

//main
int main() 
{
	//introduction();

	while (dragonHealth > 0 && playerHealth > 0)
	{
		std::cout << "\nDragon's Health: " << dragonHealth;
		std::cout << "\nYour Health: " << playerHealth;
		std::cout << "\nYour Mana: " << playerMana << std::endl;
		system("pause");

		std::cout << "\nWhat would you like to do?\n" << std::endl;
		std::cout << std::setw(20) << std::right << "(1)" << std::setw(20) << "(2)" << std::setw(20) << "(3)" << std::setw(21) << "(4)" << std::endl;
		std::cout << std::setw(21) << std::right << "Attack" << std::setw(20) << "Magic" << std::setw(20) << "Defend" << std::setw(20) << "Item" << std::endl;
		std::cin >> playerChoice;
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
		else if (nextAttack !=0 && nextAttackMod != 0) {
			std::cout << "Base Attack: " << nextAttack << std::endl;
			std::cout << "Berserker Buff : " << nextAttackMod << std::endl;
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
	}

	//// Everything needed for items
	//while (playerHealth < 100 || playerMana < 100)
	//{
	//	std::cout << "Health: " << playerHealth << std::endl;
	//	std::cout << "Mana: " << playerMana << std::endl;
	//	nextAttackMod = itemChoices(playerHealth, playerMana);
	//	std::cout << "Health: " << playerHealth << std::endl;
	//	std::cout << "Mana: " << playerMana << std::endl;
	//	std::cout << "nextAttackMod: " << nextAttackMod << std::endl;
	//}

	// George: Dragon Ability working
	//while (playerHealth > 0)
	//{
	//	//Everything needed for dragon to cast ability
	//	if (dragonValue >= 1)
	//	{
	//		dragonValue = dragonAbility(dragonValue);
	//	}
	//	else
	//	{
	//		dragonValue = dragonAbility(dragonValue);
	//	}
	//	playerHealth -= dragonValue;
	//	std::cout << playerHealth;
	//}

	////Everything needed for player to cast spell
	//int playerMana = 100;
	//int* totalMana = &playerMana;
	//while (playerMana > 0)
	//{
	//	std::cout << "Mana: " << playerMana << std::endl;

	//	nextAttack = castPlayerSpell(&playerMana);

	//	std::cout << "Mana: " << playerMana << std::endl;
	//}
	
	
	//one function takes parameter returns value
	//reference
	//pointer
	//.h file
	//.cpp file
	//comments
	//inheritance: spell class where spells are children
	//public private encapsulation
	//gui
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
	std::string name;
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
	std::cout << "\n";
	system("pause");
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
	system("pause");
	return randNum;
}