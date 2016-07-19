#ifndef DEFINITION_H
#define DEFINITION_H
#include <iostream>
#include <unordered_map>
#include <vector>
#include "trim.h"
#include "chunks.h"

class Definition {
public:
	std::string fullSentence;
	std::string signature;
	Chunks chunks;
	Definition(std::string);
private:
	std::string sign(std::string sentence);
	static bool checkChars(char v);
};

Definition::Definition(std::string sentence) {
	trim(sentence);
	signature = sign(sentence);
	fullSentence = sentence;
	chunks.add(signature);
}

bool Definition::checkChars(char v) {
	return v == ' ' || v == ',';
}

std::string Definition::sign(std::string sentence) {
	sentence.erase(remove_if(sentence.begin(), sentence.end(), checkChars), sentence.end());
	return sentence;
}

#endif