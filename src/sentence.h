#ifndef SENTENCE_H
#define SENTENCE_H
#include <iostream>
#include <unordered_map>
#include <vector>
#include "trim.h"
#include "chunkSize.h"

class Sentence {
public:

	std::string getFullSentence();
	std::string getSignature();
	ChunkSize getChunkSizes();

	Sentence(std::string sentence);

private:
	std::string fullSentence;
	std::string signature;
	ChunkSize chunkSizes;
	std::string sign(std::string sentence);
	static bool checkChars(char v);
};

Sentence::Sentence(std::string sentence) {
	trim(sentence);
	signature = sign(sentence);
	fullSentence = sentence;

	chunkSizes.add(signature);
}



std::string Sentence::getFullSentence() {
	return fullSentence;
}

std::string Sentence::getSignature() {
	return signature;
}

ChunkSize Sentence::getChunkSizes() {
	return chunkSizes;
}


bool Sentence::checkChars(char v) {
	return v == ' ' || v == ',';
}

std::string Sentence::sign(std::string sentence) {
	sentence.erase(remove_if(sentence.begin(), sentence.end(), checkChars), sentence.end());
	return sentence;
}

#endif