#ifndef MATCHER_H
#define MATCHER_H
#include "sentence.h"
#include "matches.h"
#include <iostream>
#include <vector>
#include <map>
#include <math.h>

class Matcher {
public:
	void match(Sentence &input, SourceLine source, int chunkLength);
	void resetMatches();
private:
	int counter = 0;
	int highestMatches = 0;
};

void Matcher::resetMatches() {
	highestMatches = 0;
}

void Matcher::match(Sentence &input, SourceLine source, int chunkLength) {
	std::cout << "Currently matching " << source.getFullSentence() << std::endl;
	
	int maxDiff = ceil(input.getLength() / 10);
	int diff = abs(input.getLength() - source.getLength());
	std::cout << "input length " << input.getLength() << std::endl;

	if (diff <= maxDiff) {

	std::map<std::string,int>::iterator got = input.matches.find(source.getFullSentence());
	
	ChunkSize::chunkSizeList inputChunks = input.getChunkSizes();

	    Chunks::chunkList inputChunksToMatch = inputChunks[chunkLength].get();
	    int totalChunksMatched = 0;
	    for(auto const& inputChunk: inputChunksToMatch) {
	        
	        int sourceMatch = source.getChunkCount(inputChunk);  
	        int inputMatch = input.getChunkCount(inputChunk);
	       // std::cout << "Looking at chunk " << inputChunk << std::endl;
	    	if (sourceMatch == inputMatch) {
				if (got == input.matches.end()) {
					std::pair<std::string, int> current_sentence(source.getFullSentence(), 1);
					input.matches.insert(current_sentence);
				} else {
					got->second = got->second + 1;
				}

				totalChunksMatched++;
	    	} 

			if (totalChunksMatched > highestMatches) {
				highestMatches = totalChunksMatched;
				input.setBestMatch(source.getFullSentence());
				 std::cout << "HighestMatches " << highestMatches << std::endl;
				 std::cout << "New Best match " << source.getFullSentence() << std::endl;
			}

				//std::cout << "Found " << chunkMatch << " matches " << inputChunk << " for length " << chunkLength << std::endl;

	    }

		if (totalChunksMatched <= 0) {
			//std::cout << "No chunks matched" << std::endl;
			if (got != input.matches.end()) {
				std::cout << "Erasing " << got->first << std::endl;
				input.matches.erase(got);
			}
		}
	} else {
		std::cout << "Too long" << source.getFullSentence() << std::endl;
	}

}

#endif