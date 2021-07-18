//include
#include <iostream>

//include .h
#include "Ending.h"

//ending method for ClassEnding
void ClassEnding::ending(int playerHealth, std::string mainName) {
	//if check to determine if player won or lost
	if (playerHealth <= 0) {
		std::cout << "\n\nYou were defeated by the dragon.\n\n\n";
	}
	else {
		std::cout << "\n\nCongragulations " << mainName << ", you defeated the dragon!\n\n\n";
	}
}