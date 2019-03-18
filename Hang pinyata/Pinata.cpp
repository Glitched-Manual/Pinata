#include "Pinata.h"



Pinata::Pinata()
{
	win = false;
	current_fails = 0;
	MAX_FAILS = 5;
}


Pinata::~Pinata()
{
}

void Pinata::GameLoop() 
{
	//setword
	GetGameWord().SetLetters("Manual");
	while ((win == false)&(current_fails < MAX_FAILS)) 
	{
		//getuser input
	}

}
void Pinata::DisplayFullWord()
{

}

char Pinata::UserInputChar()
{
	std::cin.clear();
	std::cin.ignore();
	char userCharGuess;
	std::cout << "Enter a letter or number" << std::endl;
	std::cin >> userCharGuess;
}