#ifndef SENTENCE_H
#define SENTENCE_H
#include <iostream>
#include <map>
#include <vector>
#include "trim.h"
#include "words.h"
#include "chunkCounter.h"

class Sentence {
public:

	std::string getFullSentence();
	std::string getSignature();
	std::string getBestMatch();
	void setBestMatch(std::string match);
	Words::wordList getWords();
	int getChunkCount(std::string chunk);
	std::map<std::string, int> matches;
	Sentence(std::string sentence);

private:
	Words words;
	std::string bestMatch;
	std::string fullSentence;
	std::string signature;
	ChunkCounter chunkCounter;
	std::string sign(std::string sentence);
	static bool checkChars(char v);
};

Sentence::Sentence(std::string sentence) {
	trim(sentence);
	signature = sign(sentence);
	fullSentence = sentence;
	chunkCounter.count(signature);
	words.create(fullSentence);
}

std::string Sentence::getBestMatch() {
	return bestMatch;
}

void Sentence::setBestMatch(std::string match) {
	bestMatch = match;
}

std::string Sentence::getFullSentence() {
	return fullSentence;
}

std::string Sentence::getSignature() {
	return signature;
}

int Sentence::getChunkCount(std::string chunk) {
	return chunkCounter.getCount(chunk);
}

Words::wordList Sentence::getWords() {
	return words.getAllWords();
}


bool Sentence::checkChars(char v) {
	return v == ' ' || v == ',';
}

std::string Sentence::sign(std::string sentence) {
	sentence.erase(remove_if(sentence.begin(), sentence.end(), checkChars), sentence.end());
	return sentence;
}

#endif