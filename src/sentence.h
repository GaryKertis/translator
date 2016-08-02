#ifndef SENTENCE_H
#define SENTENCE_H
#include <iostream>
#include <map>
#include <vector>
#include "trim.h"
#include "chunkSize.h"

class Sentence {
public:

	std::string getFullSentence();
	std::string getSignature();
	std::string getBestMatch();
	void setBestMatch(std::string match);
	ChunkSize::chunkSizeList getChunkSizes();
	Chunk &getChunk(std::string chunk);
	int getChunkCount(std::string chunk);
	int getChunkLocations(std::string chunk);
	std::map<std::string, int> matches;
	Sentence(std::string sentence);

private:
	std::string bestMatch;
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
	chunkSizes.add(sentence);
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

Chunk &Sentence::getChunk(std::string chunk) {
	return chunkSizes.getChunk(chunk);
}

int Sentence::getChunkCount(std::string chunk) {
	return getChunk(chunk).getCount();
}

int Sentence::getChunkLocations(std::string chunk) {
	return getChunk(chunk).getLocation();
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