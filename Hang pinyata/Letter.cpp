#include "Letter.h"

Letter::Letter()
{
	letter_guessed = false;
}

Letter::Letter(char the_l)
{
	actual_letter = the_l;
	letter_guessed = false;
}


Letter::~Letter()
{
}
