#include <iostream>

class Letter
{
public:
	Letter();
	Letter(char the_l);
	~Letter();
	bool ReturnLetterGuessed() { return letter_guessed; }
	void SetLetterGuessedTrue() { letter_guessed = true; }
	char GetActualLetter() { return actual_letter; }

private:
	bool letter_guessed;
	char actual_letter;
};

