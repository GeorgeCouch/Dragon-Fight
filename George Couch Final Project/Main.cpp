//Allows for input and output
#include <iostream>
//Allows for user input
#include <string>
//Allows for time waiting
#include <thread>
#include <chrono>
//Allows for cout formatting
#include <iomanip>

//include other functions
#include "DragonAbility.h"
#include "Spells.h"
#include "ItemChoices.h"
#include "Introduction.h"
#include "Ending.h"

//initialize functions
int castPlayerSpell(int* totalMana);
int playerAttack();
int playerDefend();
int itemChoices(int& playerHealth, int& playerMana);
void battle();

//Declare variables
int dragonHealth = 100;
int playerHealth = 100;
int playerMana = 100;
int randNum;
int playerChoice;
int defend = 0;
int nextAttack = 0;
int nextSpellAttack = 0;
int dragonValue = 1;
int attackMod = 0;
int dragonDamage;
int* totalMana = &playerMana;
int chooseOption;
std::string mainName = "";

//create objects
ClassIntroduction objectIntroduction;
ClassEnding objectEnding;

//main
int main()
{
	//call introduction using object and return playerName
	mainName = objectIntroduction.introduction();
	//print statuses
	std::cout << "\nDragon's Health: " << dragonHealth;
	std::cout << "\nYour Health: " << playerHealth;
	std::cout << "\nYour Mana: " << playerMana << std::endl;
	std::cout << "\n";
	system("pause");
	std::cout << "\n";
	//call battle function
	battle();
	return 0;
}

void battle() {
	//while dragon health and player health are >0 perform actions
	while (dragonHealth >= 0 && playerHealth >= 0)
	{
		//allow player to be sure of their option
		chooseOption = 0;
		while (chooseOption == 0)
		{
			//ask the player if they are sure
			int playerCheck = 2;
			while (playerCheck == 2)
			{
				//text output for choices
				std::cout << "\nWhat would you like to do?\n" << std::endl;
				std::cout << std::setw(20) << std::right << "(1)" << std::setw(20) << "(2)" << std::setw(20) << "(3)" << std::setw(21) << "(4)" << std::endl;
				std::cout << std::setw(21) << std::right << "Attack" << std::setw(20) << "Magic" << std::setw(20) << "Defend" << std::setw(20) << "Item" << std::endl;
				std::cin >> playerChoice;
				//ask player if they're sure of their choice
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
				//call playerAttack and set return value to next attack
				nextAttack = playerAttack();
				chooseOption = 1;
				break;
			case 2:
				//call castPlayerSpell and pass pointer. Set return value to nextSpellAttack
				nextSpellAttack = castPlayerSpell(&playerMana);
				chooseOption = 1;
				break;
			case 3:
				//call playerDefend and set defend to returned value
				defend = playerDefend();
				chooseOption = 1;
				break;
			case 4:
				//call itemChoices and pass playerHealth and playerMana, set nextAttackMod to returned value
				attackMod = itemChoices(playerHealth, playerMana);
				chooseOption = 1;
				break;
			default:
				std::cout << "\nPlease choose from one of the options\n";
				break;
			}
		}

		//perform normal attack if nextAttackMod = 0
		if (nextAttack != 0 && attackMod == 0) {
			dragonDamage = nextAttack;
			std::cout << "You dealt " << dragonDamage << " damage!" << std::endl;
			nextAttack = 0;
			dragonHealth -= dragonDamage;
		}
		//perform bonus attack if nextAttackMod !=0 (berserker beer consumed)
		else if (nextAttack != 0 && attackMod != 0) {
			std::cout << "Base Attack: " << nextAttack << std::endl;
			std::cout << "Berserker Beer: " << attackMod << std::endl;
			dragonDamage = nextAttack + attackMod;
			std::cout << "You dealt " << dragonDamage << " damage!" << std::endl;
			nextAttack = 0;
			attackMod = 0;
			dragonHealth -= dragonDamage;
		}
		//perform if spell is cast
		else if (nextSpellAttack != 0) {
			dragonDamage = nextSpellAttack;
			nextSpellAttack = 0;
			dragonHealth -= dragonDamage;
		}

		std::cout << "\n";
		system("pause");

		//if dragon health is >= 0 then end battle()
		if (dragonHealth <= 0) {
			//call ending using object and pass playerHealth and mainName
			objectEnding.ending(playerHealth, mainName);
		}

		//call dragonAbility and pass dragonValue, return dragon value, dragon Value determines if ability is being "charged"
		if (dragonValue >= 1)
		{
			dragonValue = dragonAbility(dragonValue);
		}
		else
		{
			dragonValue = dragonAbility(dragonValue);
		}
		//divide incoming damage in half it player is defending
		if (defend == 1)
		{
			dragonValue /= 2;
			playerHealth -= dragonValue;
			defend = 0;
		}
		else if (defend == 0)
		{
			playerHealth -= dragonValue;
		}

		//lower player's defense after dragon attack
		if (defend == 1)
		{
			std::cout << "You lower your shield...\n";
			defend = 0;
		}

		//if playerHealth <= 0 end battle()
		if (playerHealth <= 0) {
			//call ending using object and pass playerHealth and mainName
			objectEnding.ending(playerHealth, mainName);
		}

		//print statuses
		std::cout << "\nDragon's Health: " << dragonHealth;
		std::cout << "\nYour Health: " << playerHealth;
		std::cout << "\nYour Mana: " << playerMana << std::endl;
	}
}

//playerDefend function
int playerDefend()
{
	//text output and set defense to 1
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

//playerAttack function
int playerAttack()
{
	//text output and set randNum to random value between 3 and 10. Will be what damages the dragon.
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