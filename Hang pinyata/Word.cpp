#include "Word.h"

Word::Word()
{
	word_letters = new std::vector<Letter>; //forgot to add causes vector.empty() error
}
/*
Word::Word(std::vector<Letter>* passed_letter_vector)
{
	word_letters = passed_letter_vector;
}
*/

Word::~Word()
{
}

void Word::SetLetters(std::string passed_word)
{
	//if Letter vector has Letters empty it
	if (!(word_letters->empty()))
	{
		word_letters->clear();
		std::cout << "Letters cleared" << std::endl;
	}
	//add each char to a Letter class, then push class to vector
	for (unsigned int letter_count = 0; letter_count < passed_word.length(); letter_count++)
	{
		Letter* push_letter;
		if ((isalnum(passed_word[letter_count]))) // use isalnum for letters and numbers. isalpha letters. isnum for numbers 
		{
			push_letter = new Letter(passed_word[letter_count]);
			word_letters->push_back(*push_letter);
			delete push_letter;
		}
		else 
		{
			std::cout << "Word::SetLetters error : non alphanumeric character found" << std::endl;
		}
		
	}
	std::cout << "Letters set" << std::endl;
}