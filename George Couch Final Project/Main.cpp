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
void castPlayerSpell();
void castFireBall();
void castIceBlast();
void castLightningBolt();
void playerAttack();
void dragonAbility();
void chooseAction();
void playerDefend();

int dragonHealth = 100;
int playerHealth = 100;
int playerMana = 100;
int fireBall = 30;
int iceBlast = 10;
int lightningBolt = 20;
int playerSpell;
int chargeAttack = 0;
int randNum;
int playerChoice;
int defend = 0;
int playerItem;

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
		chooseAction();
		dragonAbility();
	}
}

void chooseAction()
{
	std::cout << "\nWhat would you like to do?\n" << std::endl;
	std::cout << std::setw(20) << std::right << "(1)" << std::setw(20) << "(2)" << std::setw(20) << "(3)" << std::setw(21) << "(4)" << std::endl;
	std::cout << std::setw(21) << std::right << "Attack" << std::setw(20) << "Magic" << std::setw(20) << "Defend" << std::setw(20) << "Item" << std::endl;
	std::cin >> playerChoice;
	switch (playerChoice)
	{
	case 1:
		playerAttack();
		break;
	case 2:
		castPlayerSpell();
		break;
	case 3:
		playerDefend();
		break;
	case 4:
		//Use item
		//std::cout << "\nYou now have " << playerHealth << " health and " << playerMana << " mana";
		std::cout << "\nWhich item would you like to use?\n\n";
		std::cout << std::setw(50) << std::right << "Spells and Mana Costs:" << std::endl;
		std::cout << std::setw(22) << std::right << "(1)" << std::setw(20) << "(2)" << std::setw(18) << "(3)" << std::endl;
		std::cout << std::setw(20) << std::right << "\tFire Ball" << std::setw(20) << "Ice Blast" << std::setw(20) << "Lightning Bolt" << std::endl;
		std::cout << std::setw(21) << std::right << fireBall << std::setw(20) << iceBlast << std::setw(18) << lightningBolt << std::endl;
		std::cin >> playerSpell;
		switch (playerSpell)
		{
		case 1:
			castFireBall();
			break;
		case 2:
			castIceBlast();
			break;
		case 3:
			castLightningBolt();
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void playerDefend()
{
	//Defend
	std::cout << "\nYou raise your shield and prepare for the dragon's next attack";
	for (int i = 0; i < 3; i++) {
		std::chrono::milliseconds timespan(500);
		std::cout << ".";
		std::this_thread::sleep_for(timespan);
	}
	defend = 1;
}

void dragonAbility()
{
	std::cout << "\nThe dragon is casting an ability\n";
	for (int i = 0; i < 3; i++) {
		std::chrono::milliseconds timespan(500);
		std::cout << ".";
		std::this_thread::sleep_for(timespan);
	}
	if (chargeAttack == 0)
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
	std::cout << "\nYour Health: " << playerHealth;
	std::cout << "\nYour Mana: " << playerMana << std::endl;
}

void playerAttack()
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
	std::cout << "\nYou dealt " << randNum << " damage.";
	std::cout << "\nDragon's Health: " << dragonHealth << std::endl;
	system("pause");
}

void castPlayerSpell()
{
	//std::cout << "\nYou now have " << playerHealth << " health and " << playerMana << " mana";
	std::cout << "\nWhich spell would you like to cast?\n\n";
	std::cout << std::setw(50) << std::right << "Spells and Mana Costs:" << std::endl;
	std::cout << std::setw(22) << std::right << "(1)" << std::setw(20) << "(2)" << std::setw(18) << "(3)" << std::endl;
	std::cout << std::setw(20) << std::right << "\tFire Ball" << std::setw(20) << "Ice Blast" << std::setw(20) << "Lightning Bolt" << std::endl;
	std::cout << std::setw(21) << std::right << fireBall << std::setw(20) << iceBlast << std::setw(18) << lightningBolt << std::endl;
	std::cin >> playerSpell;
	switch (playerSpell)
	{
	case 1:
		castFireBall();
		break;
	case 2:
		castIceBlast();
		break;
	case 3:
		castLightningBolt();
		break;
	default:
		break;
	}
}

void castLightningBolt()
{
	std::cout << "\nYou cast Lightning Bolt!";
	playerMana -= lightningBolt;
	for (int i = 0; i < 3; i++) {
		std::chrono::milliseconds timespan(500);
		std::cout << ".";
		std::this_thread::sleep_for(timespan);
	}
	srand(time(0));
	randNum = rand() % 15 + 25;//range between 25 and 40;
	std::cout << "\nYou dealt " << randNum << " damage.";
	std::cout << "\nLightning Bolt is very effective against dragons!";
	std::cout << "\nDragon's Health: " << dragonHealth << std::endl;
	system("pause");
}

void castIceBlast()
{
	//cast ability
	std::cout << "\nYou cast Ice Blast!";
	playerMana -= iceBlast;
	for (int i = 0; i < 3; i++) {
		std::chrono::milliseconds timespan(500);
		std::cout << ".";
		std::this_thread::sleep_for(timespan);
	}
	srand(time(0));
	randNum = rand() % 10 + 15;//range between 15 and 25;
	std::cout << "\nYou dealt " << randNum << " damage.";
	std::cout << "\nDragon's Health: " << dragonHealth << std::endl;
	system("pause");
}

void castFireBall()
{
	//cast ability
	std::cout << "\nYou cast Fire Ball!";
	playerMana -= fireBall;
	for (int i = 0; i < 3; i++) {
		std::chrono::milliseconds timespan(500);
		std::cout << ".";
		std::this_thread::sleep_for(timespan);
	}
	srand(time(0));
	randNum = rand() % 5 + 5;//range between 5 and 10;
	std::cout << "\nYou dealt " << randNum << " damage.";
	std::cout << "\nFire Ball is not very effective against dragons.";
	std::cout << "\nDragon's Health: " << dragonHealth << std::endl;
	system("pause");
}