#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int SIZE = 0;

class Word {

	std::string word;
	int WORD_ID = 0;

public:

	Word() : word("NULL") {}
	Word(std::string word) {
		this->word = word;
		SIZE++;
		WORD_ID = SIZE;
	}

	std::string getName() { return word; }

	void getWord() { 
		std::cout << "[" << WORD_ID << "]: " << word << std::endl; 
	}
	void setWord(std::string word) { 
		this->word = word; 
	}

};