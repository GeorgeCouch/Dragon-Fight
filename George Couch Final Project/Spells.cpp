//includes
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

//include h file
#include "Spells.h"

//initialize functions
int castFireBall(int* totalMana, int fireBall, int damage);
int castIceBlast(int* totalMana, int iceBlast, int damage);
int castLightningBolt(int* totalMana, int lightningBolt, int damage);

//castPlayerSpell function
int castPlayerSpell(int* totalMana)
{
	//declare variables
	int damage = 0;
	int playerSpell;
	int fireBall = 10;
	int iceBlast = 20;
	int lightningBolt = 40;
	int newDamage;
	int keepLooping = 1;

	//allow for player to choose something else if not enough mana
	while (keepLooping == 1)
	{
		//allow player to be sure about choice
		int playerCheck = 2;
		while (playerCheck == 2)
		{
			//text output
			std::cout << "\nWhich spell would you like to cast?\n\n";
			std::cout << std::setw(50) << std::right << "Spells and Mana Costs:" << std::endl;
			std::cout << std::setw(22) << std::right << "(1)" << std::setw(20) << "(2)" << std::setw(18) << "(3)" << std::setw(19) << "(4)" << std::endl;
			std::cout << std::setw(20) << std::right << "\tFire Ball" << std::setw(20) << "Ice Blast" << std::setw(20) << "Lightning Bolt" << std::setw(17) << "Main Menu" << std::endl;
			std::cout << std::setw(21) << std::right << fireBall << std::setw(20) << iceBlast << std::setw(18) << lightningBolt << std::endl;
			//ask player about their choice
			std::cin >> playerSpell;
			if (playerSpell >= 1 && playerSpell <= 3)
			{
				std::cout << "\nAre you sure you want to cast this spell?\n\n";
				std::cout << std::setw(55) << std::right << "(1) Yes, (2) No\n";
				std::cin >> playerCheck;
			}
			else
			{
				playerCheck = 1;
			}
		}
		switch (playerSpell)
		{
		case 1:
			//if playerMana >= fireball cost, call castFireBall and set newDamage to value returned, else let player choose another spell
			if (*totalMana >= fireBall) {
				newDamage = castFireBall(totalMana, fireBall, damage);
				return newDamage;
			}
			else
			{
				//return to main menu if not enough mana
				std::cout << "You don't have enough mana to cast this spell.\n";
				battle();
			}
			break;
		case 2:
			//if playerMana >= iceBlast cost, call castIceBlast and set newDamage to value returned, else let player choose another spell
			if (*totalMana >= iceBlast) {
				newDamage = castIceBlast(totalMana, iceBlast, damage);
				return newDamage;
			}
			else
			{
				//return to main menu if not enough mana
				std::cout << "You don't have enough mana to cast this spell.\n";
				battle();
			}
			break;
		case 3:
			//if playerMana >= lightningBolt cost, call castLightningBolt and set newDamage to value returned, else let player choose another spell
			if (*totalMana >= lightningBolt) {
				newDamage = castLightningBolt(totalMana, lightningBolt, damage);
				return newDamage;
			}
			else
			{
				//return to main menu if not enough mana
				std::cout << "\nYou don't have enough mana to cast this spell.\n";
				battle();
			}
			break;
		default:
			//return to main menu
			battle();
			break;
		}
	}
}

//castFireBall function
int castFireBall(int* totalMana, int fireBall, int damage)
{	
	//subtract mana from playerMana and get damage range. Return damage
	int randNum;
	std::cout << "\nYou cast Fire Ball!";
	*totalMana -= fireBall;
	for (int i = 0; i < 3; i++) {
		std::chrono::milliseconds timespan(500);
		std::cout << ".";
		std::this_thread::sleep_for(timespan);
	}
	srand(time(0));
	randNum = rand() % 5 + 5;//range between 5 and 10;
	std::cout << "\nYou dealt " << randNum << " damage.";
	damage = randNum;
	std::cout << "\nFire Ball is not very effective against dragons." << std::endl;
	return damage;
}

int castIceBlast(int* totalMana, int iceBlast, int damage)
{
	//subtract mana from playerMana and get damage range. Return damage
	int randNum;
	std::cout << "\nYou cast Ice Blast!";
	*totalMana -= iceBlast;
	for (int i = 0; i < 3; i++) {
		std::chrono::milliseconds timespan(500);
		std::cout << ".";
		std::this_thread::sleep_for(timespan);
	}
	srand(time(0));
	randNum = rand() % 10 + 15;//range between 15 and 25;
	std::cout << "\nYou dealt " << randNum << " damage." << std::endl;
	damage = randNum;
	return damage;
}

int castLightningBolt(int* totalMana, int lightningBolt, int damage)
{
	//subtract mana from playerMana and get damage range. Return damage
	int randNum;
	std::cout << "\nYou cast Lightning Bolt!";
	*totalMana -= lightningBolt;
	for (int i = 0; i < 3; i++) {
		std::chrono::milliseconds timespan(500);
		std::cout << ".";
		std::this_thread::sleep_for(timespan);
	}
	srand(time(0));
	randNum = rand() % 15 + 25;//range between 25 and 40;
	std::cout << "\nYou dealt " << randNum << " damage.";
	damage = randNum;
	std::cout << "\nLightning Bolt is very effective against dragons!" << std::endl;
	return damage;
}