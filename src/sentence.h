#ifndef SENTENCE_H
#define SENTENCE_H
#include <iostream>
#include <unordered_map>
#include <vector>
#include "trim.h"
#include "chunks.h"

class Sentence {
public:
	std::string fullSentence;
	std::string signature;
	Chunks chunks;
	Sentence(std::string);
private:
	std::string sign(std::string sentence);
	static bool checkChars(char v);
};

Sentence::Sentence(std::string sentence) {
	trim(sentence);
	signature = sign(sentence);
	fullSentence = sentence;
	chunks.add(signature);
}

bool Sentence::checkChars(char v) {
	return v == ' ' || v == ',';
}

std::string Sentence::sign(std::string sentence) {
	sentence.erase(remove_if(sentence.begin(), sentence.end(), checkChars), sentence.end());
	return sentence;
}

#endif