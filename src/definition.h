#ifndef DEFINITION_H
#define DEFINITION_H
#include <iostream>
#include "trim.h"

class Definition {
public:
	std::string fullSentence;
	std::string signature;
	Definition(std::string);
};

Definition::Definition(std::string sentence) {
	trim(sentence);
	signature = sentence;
	fullSentence = sentence;
}

#endif