#ifndef DEFINITION_H
#define DEFINITION_H
#include <iostream>
#include "trim.h"

class Definition {
public:
	std::string fullSentence;
	std::string signature;
	std::string hash;
	Definition(std::string);
};

Definition::Definition(std::string sentence) {
	trim(sentence);
	fullSentence = sentence;
}

#endif