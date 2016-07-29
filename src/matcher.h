#ifndef MATCHER_H
#define MATCHER_H
#include "sentence.h"
#include "matches.h"
#include <iostream>
#include <vector>

class Matcher {
public:
	Sentence match(Sentence input, Sentence source);
	void processChunk(Sentence input, void (*callback)(std::string));
	static void nameChunk(std::string chunk);
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
	processChunk(input, nameChunk);
  return source;
}

#endif