#include "word.h"
#include <numeric>
#include <string>
#include <regex>

class Group {

	std::string title;
	std::vector<Word*> words;

public:

	Group() : title("NULL") {};

	Group(std::string title) {
		this->title = title;
		words.resize(0);
	}

	Group(std::string title, Word* first_word) {
		this->title = title;
		words.push_back(first_word);
	}
 
	std::string getGroupTitle() {
		return title;
	}
	std::vector<Word*> getGroupWords(){
		return words;
	}

	void setGroupTitle(std::string title) {
		this->title = title;
	}


	void setGroupWords(std::vector<Word*> words) {
		this->words.clear();
		for (unsigned int i = 0; i < words.size(); i++) {
			this->words.push_back(words[i]);
		}
	}

	void addWord(Word* word) {
		words.push_back(word);
	}

	void addWords() {
		std::string titleOfNewGroup;
		std::cin >> titleOfNewGroup;
		std::regex r("[A-Z a-z �-� �-� 0-9]*");
		if (!regex_match(titleOfNewGroup, r)) {
			std::cout << "You can't use symbols except letters and digits, try again: ";
			std::cin >> titleOfNewGroup;
		}
		this->setGroupTitle(titleOfNewGroup);

		std::cout << "Create some words" << std::endl;
		bool stopCreatingWords = false;
		while (!stopCreatingWords) {
			Word* newWord = new Word();
			std::cout << "Type the word: ";
			std::string nameOfNewWord;
			std::getline(std::cin, nameOfNewWord);
			if (std::cin.fail())break;
			newWord->setWord(nameOfNewWord);
			this->addWord(newWord);
			std::cout << "Stop creating words?(0 - No, 1 - Yes): ";
			std::cin >> stopCreatingWords;
		}
		std::cout << "Group " << this->getGroupTitle() << " was created." << std::endl;
	}
	void printWords() {
		for (unsigned int i = 0; i < words.size(); i++) {
			words.at(i)->getWord();
		}
	}

	bool operator==(Group& gr2) {
		std::cout << "operator==" << std::endl;
		if (this->getGroupWords().size() == gr2.getGroupWords().size()) {
			for (unsigned int i = 0; i < gr2.getGroupWords().size(); i++) {
				if (this->getGroupWords().at(i) != gr2.getGroupWords().at(i)) {
					return false;
				}
			}
			return true;
		}
	}
	bool operator!=(Group& gr2) {
		std::cout << "operator!=" << std::endl;
		if (this->getGroupWords().size() == gr2.getGroupWords().size()) {
			for (unsigned int i = 0; i < gr2.getGroupWords().size(); i++) {
				if (this->getGroupWords().at(i) != gr2.getGroupWords().at(i)) {
					return true;
				}
			}
			return false;
		}
	}
	bool operator<(Group& gr2) {
		std::cout << "operator<" << std::endl;
		if (this->getGroupWords().size() < gr2.getGroupWords().size()) {
			return true;
		}
		else { return false; }
	}
	bool operator>(Group& gr2){
		std::cout << "operator<" << std::endl;
		if (this->getGroupWords().size() < gr2.getGroupWords().size()) {
			return false;
		}
		else { return true; }
	}
	Group& operator=(Group& gr2) {
		this->title = gr2.getGroupTitle();
		this->words.clear();
		for (unsigned int i = 0; i < gr2.words.size(); i++) {
			this->words.push_back(gr2.words[i]);
		}
		return *this;
	}
};

std::ostream& operator<<(std::ostream& os, Group* group) {
	os << group->getGroupTitle() << " | Count of Words: " << group->getGroupWords().size();
	return os;
}