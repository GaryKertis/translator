#ifndef SENTENCE_H
#define SENTENCE_H
#include <iostream>
#include <map>
#include "trim.h"
#include "chunk.h"

class Sentence {
public:
	typedef std::map<std::string, Chunk> chunkList;

	std::string getFullSentence();
	std::string getSignature();

	std::string getBestMatch();
	void setBestMatch(std::string match);

	chunkList getChunks();
	Chunk &getChunk(std::string chunk);
	int getChunkCount(std::string chunk);
	int getChunkLocations(std::string chunk);
	void addChunk(std::string sentence);

	Sentence(std::string sentence);

private:
	std::string bestMatch;
	std::string fullSentence;
	std::string signature;
	chunkList chunks;
	std::string sign(std::string sentence);
	static bool checkChars(char v);
};

Sentence::Sentence(std::string sentence) {
	trim(sentence);
	signature = sign(sentence);
	fullSentence = sentence;
	addChunk(sentence);
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
	chunkList::iterator got = chunks.find(chunk);
	if (got != chunks.end()) {
		return got->second;
	}
}

int Sentence::getChunkCount(std::string chunk) {
	return getChunk(chunk).getCount();
}

int Sentence::getChunkLocations(std::string chunk) {
	return getChunk(chunk).getLocation();
}

Sentence::chunkList Sentence::getChunks() {
	return chunks;
}


void Sentence::addChunk(std::string sentence) {
//find all chunks with given length of size
	for(int i = 0; sentence[i] != '\0';) {

		int remaining = sentence.length() - i;

		std::string chunk_name = sentence.substr(i,1);
		int chunk_location = i;
		int chunk_length = chunk_name.length();

		chunkList::iterator it = chunks.find(chunk_name);
		
		if (it == chunks.end()) {
			Chunk chunk(chunk_name, chunk_location, 1);
			std::pair<std::string, Chunk> current_chunk(chunk_name, chunk);
			chunks.insert(current_chunk);
		} else {
			it->second.incrementCount();
		}
		i++;
	}
}


bool Sentence::checkChars(char v) {
	return v == ' ' || v == ',';
}

std::string Sentence::sign(std::string sentence) {
	sentence.erase(remove_if(sentence.begin(), sentence.end(), checkChars), sentence.end());
	return sentence;
}

#endif