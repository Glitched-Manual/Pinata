#include "Word.h"
#include <string>
#ifndef PINATA_H
#define PINTATA_H
class Pinata
{
public:
	Pinata();
	~Pinata();

	Word* GetGameWord() { return game_word; }
	void DisplayFullWord();
	void DisplayGuessedLetters();
	void GameLoop();
	char UserInputChar();
	bool CheckUserInput(char passed_char,Word& passed_word);
	bool CheckIfPlayerwon();
	int GetLettersLeft();
	
private:
	bool win;
	bool quit;
	Word* game_word;
	//std::vector<Letter>* game_letters;
	int current_fails;
	int MAX_FAILS;
};
#endif // end of PINATA_H
