#include "Letter.h"
#include <vector>
#include <cctype>
class Word
{
public:
	Word();
	//Word(std::vector<Letter>* passed_letter_vector);
	~Word();
	void SetLetters(std::string passed_word);
	std::vector<Letter>& GetWordLetters() { return *word_letters; }

private:
	std::vector<Letter>* word_letters;
};

