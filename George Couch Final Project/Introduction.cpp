//includes
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

//include .h file
#include "Introduction.h"

//declare variable
std::string name = "";

//introduction method for ClassIntroduction
std::string ClassIntroduction::introduction()
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
	//return name
	return name;
}