#ifndef MATCHER_H
#define MATCHER_H
#include "sentence.h"
#include "matches.h"
#include <iostream>
#include <vector>
#include <map>

class Matcher {
public:
	void match(Sentence &input, Sentence source, int chunkLength);
private:
	int counter = 0;
	int highestMatches = 0;
};

void Matcher::match(Sentence &input, Sentence source, int chunkLength) {
	std::cout << "Currently matching " << source.getFullSentence() << std::endl;
	ChunkSize::chunkSizeList inputChunks = input.getChunkSizes();

	    Chunks::chunkList inputChunksToMatch = inputChunks[chunkLength].get();
	    int totalChunksMatched = 0;
	    for(auto & inputChunk: inputChunksToMatch) {
	        
	        int chunkMatch = source.getChunkCount(inputChunk.getName());  
	        std::cout << inputChunk.getName() << inputChunk.getLocation() << std::endl;
	    	if (chunkMatch > 0) {

				std::map<std::string,int>::iterator got = input.matches.find(source.getFullSentence());

				if (got == input.matches.end()) {
					std::pair<std::string, int> current_chunk(source.getFullSentence(), 1);
					input.matches.insert(current_chunk);
				} else {
					got->second = got->second + 1;
				}

				totalChunksMatched += chunkMatch;
	    	} 

				if (totalChunksMatched > highestMatches) {
					highestMatches = totalChunksMatched;
					input.setBestMatch(source.getFullSentence());
					std::cout << "HighestMatches " << highestMatches << std::endl;
					std::cout << "New Best match " << source.getFullSentence() << std::endl;
				}
				//std::cout << "Found " << chunkMatch << " matches " << inputChunk << " for length " << chunkLength << std::endl;

	    }

}

#endif