#include <iostream>

class Letter
{
public:
	Letter(char the_l);
	~Letter();
	bool ReturnLetterGuessed() { return letter_guessed; }
	char ReturnActualLetter() { return actual_letter; }

private:
	bool letter_guessed;
	char actual_letter;
};

