#ifndef MATCHER_H
#define MATCHER_H
#include "sentence.h"
#include "matches.h"
#include <iostream>
#include <vector>
#include <map>

class Matcher {
public:
	Sentence match(Sentence input, Sentence source);
	void processChunk(Sentence input, void (*callback)(std::string));
	static void nameChunk(std::string chunk);
private:
	int counter = 0;
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

Sentence Matcher::match(Sentence input, Sentence source) {
	//processChunk(input, nameChunk);
	std::cout << "Currently matching " << input.getFullSentence() << " to " << source.getFullSentence() << std::endl;
	ChunkSize::chunkSizeList inputChunks = input.getChunkSizes().getAllChunks();
	ChunkSize::chunkSizeList sourceChunks = source.getChunkSizes().getAllChunks();

	for (auto it = inputChunks.begin(); it != inputChunks.end(); ++it) {
	    Chunks::chunkList inputChunksToMatch = inputChunks[it->first].get();
	    for(auto const& inputChunk: inputChunksToMatch) {
	      
		    Chunks::chunkList sourceChunksToMatch = sourceChunks[it->first].get();
		    for(auto const& sourceChunk: sourceChunksToMatch) {
      
		    	if (inputChunk == sourceChunk) {

					std::map<int,int>::iterator got = input.matches.find(it->first);

					if (got == input.matches.end()) {

						std::pair<int, int> current_chunk(it->first, 1);
						input.matches.insert(current_chunk);

					} else {

						got->second = got->second + 1;

					}

					std::cout << "Found match " << inputChunk << " for length " << it-> first << std::endl;

		    	}

		    }
	    }
  	}

}

#endif