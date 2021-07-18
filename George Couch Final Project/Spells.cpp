#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

#include "Spells.h"

int castFireBall(int* totalMana, int fireBall, int damage);
int castIceBlast(int* totalMana, int iceBlast, int damage);
int castLightningBolt(int* totalMana, int lightningBolt, int damage);

int castPlayerSpell(int* totalMana)
{
	int damage = 0;
	int playerSpell;
	int fireBall = 30;
	int iceBlast = 10;
	int lightningBolt = 20;
	int newDamage;
	int keepLooping = 1;
	while (keepLooping == 1)
	{
		int playerCheck = 2;
		while (playerCheck == 2)
		{
			std::cout << "\nWhich spell would you like to cast?\n\n";
			std::cout << std::setw(50) << std::right << "Spells and Mana Costs:" << std::endl;
			std::cout << std::setw(22) << std::right << "(1)" << std::setw(20) << "(2)" << std::setw(18) << "(3)" << std::endl;
			std::cout << std::setw(20) << std::right << "\tFire Ball" << std::setw(20) << "Ice Blast" << std::setw(20) << "Lightning Bolt" << std::endl;
			std::cout << std::setw(21) << std::right << fireBall << std::setw(20) << iceBlast << std::setw(18) << lightningBolt << std::endl;
			std::cout << "\nEnter 4 to go back to main menu.";
			std::cin >> playerSpell;
			if (playerSpell >= 1 && playerSpell <= 3)
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
		switch (playerSpell)
		{
		case 1:
			if (*totalMana >= fireBall) {
				newDamage = castFireBall(totalMana, fireBall, damage);
				return newDamage;
			}
			else
			{
				std::cout << "You don't have enough mana to cast this spell.\n";
			}
			break;
		case 2:
			if (*totalMana >= iceBlast) {
				newDamage = castIceBlast(totalMana, iceBlast, damage);
				return newDamage;
			}
			else
			{
				std::cout << "You don't have enough mana to cast this spell.\n";
			}
			break;
		case 3:
			if (*totalMana >= lightningBolt) {
				newDamage = castLightningBolt(totalMana, lightningBolt, damage);
				return newDamage;
			}
			else
			{
				std::cout << "You don't have enough mana to cast this spell.\n";
			}
			break;
		default:
			battle();
			break;
		}
	}
}

int castFireBall(int* totalMana, int fireBall, int damage)
{
	//cast ability
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
	system("pause");
	return damage;
}

int castIceBlast(int* totalMana, int iceBlast, int damage)
{
	int randNum;
	//cast ability
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
	system("pause");
	return damage;
}

int castLightningBolt(int* totalMana, int lightningBolt, int damage)
{
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
	system("pause");
	return damage;
}