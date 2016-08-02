#ifndef MATCHER_H
#define MATCHER_H
#include "sentence.h"
#include "matches.h"
#include <iostream>
#include <vector>
#include <map>

class Matcher {
public:
	void match(Sentence &input, Sentence &source, int chunkLength);
private:
	int counter = 0;
	int highestMatches = 0;
};

void Matcher::match(Sentence &input, Sentence &source, int chunkLength) {

	ChunkSize::chunkSizeList inputChunks = input.getChunkSizes();
	Chunks::chunkList inputChunksToMatch = inputChunks[chunkLength].get();

	    int totalChunksMatched = 0;
	    for(Chunks::chunkList::iterator inputChunk = inputChunksToMatch.begin(); inputChunk != inputChunksToMatch.end(); inputChunk++) {
	        
	        int sourceMatches = source.getChunkLocations(inputChunk->first);
	        int inputMatches = inputChunk->second.getLocation();

	    	if (sourceMatches != 0 && sourceMatches == inputMatches) {

				std::map<std::string,int>::iterator got = input.matches.find(source.getFullSentence());

				if (got == input.matches.end()) {
					std::pair<std::string, int> current_chunk(source.getFullSentence(), 1);
					input.matches.insert(current_chunk);
				} else {
					got->second = got->second + 1;
				}
				totalChunksMatched++;
	    	} 


			if (totalChunksMatched > highestMatches) {
	        	std::cout << totalChunksMatched << std::endl;
				highestMatches = totalChunksMatched;
				input.setBestMatch(source.getFullSentence());
				std::cout << "HighestMatches " << highestMatches << std::endl;
				std::cout << "New Best match " << source.getFullSentence() << std::endl;
			}

	    }

}

#endif