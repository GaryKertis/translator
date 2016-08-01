#ifndef CHUNKS_H
#define CHUNKS_H
#include <iostream>
#include <map>
#include <vector>
#include "chunk.h"

class Chunks {

public:
	typedef std::vector<Chunk> chunkList;

	void add(Chunk chunk);
	chunkList get();
private:
	chunkList chunks;
};

Chunks::chunkList Chunks::get() {
	return chunks;
}

void Chunks::add(Chunk chunk) {
	chunks.push_back(chunk);
}

#endif