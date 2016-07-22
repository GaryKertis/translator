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
	for (auto it = input.chunks.items.begin(); it != input.chunks.items.end(); ++it) {
    Chunks::chunkList chunksToMatch = input.chunks.list(it->first);
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