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
	std::vector<int> getBestMatchLocations();
	void setBestMatch(std::string match, std::vector<int> saveLocations);

	chunkList getChunks();
	Chunk &getChunk(std::string chunk);

	int getChunkCount(std::string chunk);
	std::vector<int> getChunkLocations(std::string chunk);
	bool hasChunkLocation(std::string chunk, int location);

	void addChunk(std::string sentence);

	Sentence(std::string sentence);

private:
	std::string bestMatch;
	std::string fullSentence;
	std::string signature;
	std::vector<int> bestMatchLocations;
	chunkList chunks;
	std::string sign(std::string sentence);
	static bool checkChars(char v);
};

#endif