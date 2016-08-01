#ifndef WORDS_H
#define WORDS_H
#include <iostream>
#include <vector>
#include "wordSplitter.h"

class Words {

public:
	typedef std::vector<std::string> wordList;
	
	wordList getAllWords();
	std::string getWord (int i);
	void create(std::string sentence);
private:
	wordList words;
};

void Words::create(std::string sentence) {
	words = wordSplitter(sentence, " ");
}

std::string Words::getWord(int i) {
	return words[i];
}

Words::wordList Words::getAllWords() {
	return words;
}


#endif