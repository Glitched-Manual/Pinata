#include "Word.h"
#ifndef PINATA_H
#define PINTATA_H
class Pinata
{
public:
	Pinata();
	~Pinata();

	Word GetGameWord() { return game_word; }
	void DisplayFullWord();
	void GameLoop();
	char UserInputChar();
private:
	bool win;
	Word game_word;
	int current_fails;
	int MAX_FAILS;
};
#endif // end of PINATA_H
