#ifndef SENTENCE_H
#define SENTENCE_H
#include <iostream>
#include <map>
#include <vector>
#include "trim.h"
#include "chunkSize.h"
#include "chunkCounter.h"

class Sentence {
public:

	std::string getFullSentence();
	std::string getSignature();
	std::string getBestMatch();
	void setBestMatch(std::string match);
	ChunkSize::chunkSizeList getChunkSizes();
	int getChunkCount(std::string chunk);
	std::map<std::string, int> matches;
	Sentence(std::string sentence);

private:
	std::string bestMatch;
	std::string fullSentence;
	std::string signature;
	ChunkSize chunkSizes;
	ChunkCounter chunkCounter;
	std::string sign(std::string sentence);
	static bool checkChars(char v);
};

Sentence::Sentence(std::string sentence) {
	trim(sentence);
	signature = sign(sentence);
	fullSentence = sentence;
	chunkSizes.add(signature);
	chunkCounter.count(signature);
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

ChunkSize::chunkSizeList Sentence::getChunkSizes() {
	return chunkSizes.getAllChunks();
}


bool Sentence::checkChars(char v) {
	return v == ' ' || v == ',';
}

std::string Sentence::sign(std::string sentence) {
	sentence.erase(remove_if(sentence.begin(), sentence.end(), checkChars), sentence.end());
	return sentence;
}

#endif