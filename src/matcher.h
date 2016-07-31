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
	void processChunk(Sentence input, void (*callback)(std::string));
	static void nameChunk(std::string chunk);
private:
	int counter = 0;
	int highestMatches = 0;
};

void Matcher::nameChunk(std::string chunk) {
	std::cout << "Currently processing " << chunk << std::endl;
}

void Matcher::processChunk(Sentence input, void (*callback)(std::string)) {

	ChunkSize::chunkSizeList chunks = input.getChunkSizes().getAllChunks();

	for (auto it = chunks.begin(); it != chunks.end(); ++it) {
	    Chunks::chunkList chunksToMatch = chunks[it->first].get();
	    for(auto const& chunk: chunksToMatch) {
	      (*callback)(chunk);
	    }
  	}
}

void Matcher::match(Sentence &input, Sentence source, int chunkLength) {
	std::cout << "Currently matching " << source.getFullSentence() << std::endl;
	ChunkSize::chunkSizeList inputChunks = input.getChunkSizes().getAllChunks();

	    Chunks::chunkList inputChunksToMatch = inputChunks[chunkLength].get();
	    int totalChunksMatched = 0;
	    for(auto const& inputChunk: inputChunksToMatch) {
	        
	        int chunkMatch = source.getChunkCounter().getCount(inputChunk);  

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
					highestMatches = chunkMatch;
					input.setBestMatch(source.getFullSentence());
					std::cout << "New Best match" << source.getFullSentence() << std::endl;
				}
				//std::cout << "Found " << chunkMatch << " matches " << inputChunk << " for length " << chunkLength << std::endl;

	    }

}

#endif