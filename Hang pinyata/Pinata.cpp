#include "Pinata.h"

Pinata::Pinata()
{
	game_word = new Word();
	win = false;
	quit = false;
	current_fails = 0;
	MAX_FAILS = 5;
	GameLoop();
}

Pinata::~Pinata()
{
}

void Pinata::GameLoop() 
{	
	GetGameWord()->SetLetters("Manual"); //set game word
	std::cout << "Welcome to a new game of Pinata" << std::endl;
	char the_letter;
	int letters_left;
	while ((win == false)&(current_fails < MAX_FAILS)) 
	{
		letters_left = GetLettersLeft();
		DisplayGuessedLetters();
		std::cout << "Please enter a letter or number " << std::endl;
		the_letter = UserInputChar();
		if (CheckUserInput((the_letter),*game_word))
		{
			std::cout << "congrats you got a letter correct!" << std::endl;
			if (letters_left > 0)
			{
				std::cout << "you have " << letters_left << " letters to go!!" << std::endl;
			}
			else
			{
				std::cout << "Wow you got all the letters!!" << std::endl;
				win = true;
			}
		}
		else 
		{
			std::cout << "The letter you selected \"" << the_letter <<"\" is wrong."<< std::endl;
			current_fails++;
			std::cout << "you have " << MAX_FAILS - current_fails << "\" strikes left." << std::endl;			
		}
		//getuser input
		if (quit) break;
	}
}
void Pinata::DisplayFullWord()
{
	for (unsigned int pw = 0; pw < game_word->GetWordLetters().size(); pw++)
	{
		Letter* temp_letter = new Letter();
		*temp_letter = GetGameWord()->GetWordLetters().at(pw);
		std::cout << temp_letter->GetActualLetter();
		delete temp_letter;
	}
	std::cout<<"" << std::endl;
}

char Pinata::UserInputChar()
{	
	std::string userInput;
	char userCharGuess;
	std::cin >> userInput;
	if (userInput == "quit") 
	{
		quit = true;
		userCharGuess = ' ';
		std::cout << "You chose to quit" << std::endl;
	}
	else if ((userInput.length() > 1) | (userInput.length() == 0))
	{
		userCharGuess = ' ';
		std::cout << "Try a single letter or number" << std::endl;
	}
	else
	{
		if (!(isalnum(userInput[(userInput.length()) - 1])))
		{
			userCharGuess = ' ';
			std::cout << "not a reconized number or letter" << std::endl;

		}
		else
		{
			userCharGuess = userInput[(userInput.length()) - 1];
			std::cout << "You guessed \"" << userInput[(userInput.length()) - 1] << "\"." << std::endl;
		}
	}
	std::cin.clear();
	std::cin.ignore();
	return userCharGuess;
}

bool Pinata::CheckUserInput(char passed_char,Word& passed_word)
{
	if (!(GetGameWord()->GetWordLetters().empty()))
	{
		bool correct_guess = false;
	for (unsigned int gi = 0; gi < GetGameWord()->GetWordLetters().size(); gi++)
	{		
		Letter* temp_letter = new Letter();
		*temp_letter = GetGameWord()->GetWordLetters().at(gi);
		//std::cout <<"the letter == "<< temp_letter->GetActualLetter() << std::endl; prints all letters?
		if ((passed_char == temp_letter->GetActualLetter())| (toupper(passed_char) == temp_letter->GetActualLetter()))
		{			
			if (temp_letter->ReturnLetterGuessed() == false) // messed this up by adding true by mistake
			{
				GetGameWord()->GetWordLetters().at(gi).SetLetterGuessedTrue(); //non pointer
				//temp_letter->SetLetterGuessedTrue(); //not working
				std::cout << "Letter true " << temp_letter->ReturnLetterGuessed() << std::endl;
				correct_guess = true; // forgot to add a return true lol ,changed to true duplicate letters

			}
			else {
				continue;
			}
		}
		delete temp_letter;
	}
	return correct_guess;
	}
	else
	{
		std::cout << "Pinata::CheckUserInput error : Vector arrary found empty" << std::endl;
		return false;
	}
}
bool Pinata::CheckIfPlayerwon()
{	
	if (!(GetGameWord()->GetWordLetters().empty()))
	{
		int letters_left = GetLettersLeft();
		
		if (letters_left > 0)
		{
			std::cout << "You have " << (static_cast<int>(GetGameWord()->GetWordLetters().size()) - letters_left) << " letters left to guess" << std::endl;
			return false;
		}
		return true;
	}
	else 
	{
		std::cout << "Pinata::CheckIfPlayerwon() error : Vector arrary found empty" << std::endl;
		return false;
	}
}

int Pinata::GetLettersLeft()
{	
	if (!(GetGameWord()->GetWordLetters().empty()))
	{
		int letters_left = 0;
		for (unsigned int pw = 0; pw < GetGameWord()->GetWordLetters().size(); pw++)
		{
			Letter* temp_letter = new Letter();
			*temp_letter = GetGameWord()->GetWordLetters().at(pw); // copies word_letters to temp_letter. temp_letter is not original. alter via get members			
			if (temp_letter->ReturnLetterGuessed() == false)
			{
				++letters_left;
				std::cout << "letter " << pw << " == false" << std::endl;
			}
			else
			{
				std::cout << "letter " << pw << " == true" << std::endl;
			}
			delete temp_letter;
		}
		return letters_left -1; // -1 because coding starts with 0 not 1
	}
	else 
	{
		std::cout << "Pinata::CheckIfPlayerwon() error : Vector arrary found empty" << std::endl;
		quit = true;
		return 0;
	}		
}

void Pinata::DisplayGuessedLetters()
{
	if (!(GetGameWord()->GetWordLetters().empty()))
	{
		//check if true print letter
		for (unsigned int pw = 0; pw < GetGameWord()->GetWordLetters().size(); pw++)
		{
			Letter* temp_letter = new Letter();
			*temp_letter = GetGameWord()->GetWordLetters().at(pw);
			if (temp_letter->ReturnLetterGuessed() == true)
			{
				std::cout << temp_letter->GetActualLetter() << " ";
			}
			else
			{
				std::cout << "__ ";
			}
			delete temp_letter;
		}
		std::cout << std::endl;
	}
}