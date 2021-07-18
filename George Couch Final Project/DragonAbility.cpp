#include <iostream>
#include <chrono>
#include <thread>

#include "DragonAbility.h";

void chargeFireBreath(int& dragonValue);
void wingGust(int& damage);
void razorSwipe(int& damage);
void fireBreath(int& damage);

int dragonAbility(int dragonValue)
{
	int damage;
	int randNum;

	// Change this to be an inherited something
	std::cout << "\nThe dragon is casting an ability";
	for (int i = 0; i < 3; i++) {
		std::chrono::milliseconds timespan(500);
		std::cout << ".";
		std::this_thread::sleep_for(timespan);
	}
	if (dragonValue >= 1)
	{
		srand(time(0));
		randNum = rand() % 3 + 1;//random number between 1 and 3
	}
	else
	{
		randNum = 4;
	}
	switch (randNum)
	{
	case 1:
		chargeFireBreath(dragonValue);
		return dragonValue;
		break;
	case 2:
		wingGust(damage);
		return damage;
		break;
	case 3:
		razorSwipe(damage);
		return damage;
		break;
	case 4:
		fireBreath(damage);
		return damage;
		break;
	default:
		break;
	}
}

void chargeFireBreath(int& dragonValue)
{
	//Charging up Fire Breath
	std::cout << "\nThe dragon is charging an attack\n" << std::endl;
	system("pause");
	dragonValue = 0;
}

void wingGust(int& damage)
{
	//Wing gust
	std::cout << "\nDragon casts wing gust!\n" << std::endl;
	system("pause");
	damage = 30;
}

void razorSwipe(int& damage)
{
	//Razor swipe
	std::cout << "\nDragon casts razor swipe!\n" << std::endl;
	system("pause");
	damage = 10;
}

void fireBreath(int& damage)
{
	//casting fire breath
	std::cout << "\nDragon casts fire breath!\n" << std::endl;
	system("pause");
	damage = 60;
}