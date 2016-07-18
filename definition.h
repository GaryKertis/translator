#ifndef DEFINITION_H
#define DEFINITION_H
#include <iostream>

class Definition {
public:
	std::string fullSentence;
	std::string signature;
	std::string hash;
	void create(std::string);
};


void Definition::create(std::string sentence) {
	fullSentence = sentence;
	std::cout << sentence;
}

#endif