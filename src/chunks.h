#ifndef CHUNKS_H
#define CHUNKS_H
#include <iostream>
#include <map>
#include <map>
#include "chunk.h"

class Chunks {

public:
	typedef std::map<std::string, Chunk> chunkList;

	void add(Chunk chunk);
	chunkList &get();
	Chunk &getChunk(std::string chunk);
private:
	chunkList chunks;
};

Chunks::chunkList &Chunks::get() {
	return chunks;
}

void Chunks::add(Chunk chunk) {
	std::pair<std::string, Chunk> current_chunk(chunk.getName(), chunk);
	chunks.insert(current_chunk);
}

Chunk &Chunks::getChunk(std::string chunk) {
	chunkList::iterator got = chunks.find(chunk);
	if (got != chunks.end()) {
		return got->second;
	}
}

#endif