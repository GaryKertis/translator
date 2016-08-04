#ifndef SENTENCE_H
#define SENTENCE_H
#include <iostream>
#include <map>
#include "trim.h"
#include "chunk.h"
#include "alphabet.h"

class Sentence {
public:
	typedef std::map<std::string, Chunk> chunkList;

	std::string getFullSentence();
	std::string getSignature();

	std::string getBestMatch();
	std::vector<int> getBestMatchLocations();
	void setBestMatch(std::string, std::vector<int>);

	chunkList getChunks();
	Chunk &getChunk(std::string);

	int getChunkCount(std::string);
	std::vector<int> getChunkLocations(std::string);
	bool hasChunkLocation(std::string, int);

	void addChunk(std::string);
	void addChunk(Alphabet);

	Sentence(std::string);
	Sentence(Alphabet);

private:
	std::string bestMatch;
	std::string fullSentence;
	std::string signature;
	std::vector<int> bestMatchLocations;
	chunkList chunks;
	std::string sign(std::string);
	static bool checkChars(char);
};

#endif