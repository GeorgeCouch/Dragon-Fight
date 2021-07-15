//Allows for input and output
#include <iostream>
//Allows for user input
#include <string>
//Allows for time waiting
#include <thread>
#include <chrono>
//Allows for cout formatting
#include <iomanip>

void dragonFight();

int dragonHealth = 100;
int playerHealth = 100;
int playerMana = 100;
int fireBall = 30;
int iceBlast = 10;
int lightningBolt = 20;
int playerSpell;
int chargeAttack = 0;
int randNum;

//main
int main() 
{
	//Description of what the program does
	std::cout << "\n\n\t****In this program you'll be fighting a dragon!***\n";
	std::cout << "\nDefeat the dragon before it defeats you!";
	std::cout << "\nanage your mana when casting spells";
	//ask the user for their name
	std::cout << "\nWhat is your name adventurer?\n";
	std::string name;
	getline(std::cin, name);
	//Greet by name
	std::cout << name + " we wish you well in your battle...";
	std::cout << "\n\nThe fight is beginning...";
	dragonFight();
	
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

void dragonFight()
{
	while (dragonHealth > 0 && playerHealth > 0)
	{
		std::cout << "\nDragon's Health: " << dragonHealth;
		std::cout << "\nYour Health: " << playerHealth;
		std::cout << "\nYour Mana: " << playerMana << std::endl;
		system("pause");
		std::cout << "\nThe dragon is casting an ability\n";
		for (int i = 0; i < 3; i++) {
			std::chrono::milliseconds timespan(500);
			std::cout << ".";
			std::this_thread::sleep_for(timespan);
		}
		if (chargeAttack == 0)
		{
			srand(time(0));
			randNum = rand() % 3;
		}
		else
		{
			randNum = 4;
		}
		switch (randNum)
		{
		case 1:
			//Charging up Fire Breath
			chargeAttack = 1;
			break;
		case 2:
			//Wing gust
			break;
		case 3:
			//Razor swipe
			break;
		case 4:
			//casting fire breath
			break;
		default:
			break;
		}
		std::cout << "\nYou now have " << playerHealth << " health and " << playerMana << " mana";
		std::cout << "\nWhat ability would you like to use?\n\n";
		std::cout << std::setw(50) << std::right << "Spells and Mana Costs:" << std::endl;
		std::cout << std::setw(22) << std::right << "(1)" << std::setw(20) << "(2)" << std::setw(18) << "(3)" << std::endl;
		std::cout << std::setw(20) << std::right << "\tFire Ball" << std::setw(20) << "Ice Blast" << std::setw(20) << "Lightning Bolt" << std::endl;
		std::cout << std::setw(21) << std::right << fireBall << std::setw(20) << iceBlast << std::setw(18) << lightningBolt << std::endl;
		std::cin >> playerSpell;
		switch (playerSpell)
		{
		case 1:
			//cast ability
			break;
		case 2:
			//cast ability
			break;
		case 3:
			//cast ability
			break;
		default:
			break;
		}
	}
}