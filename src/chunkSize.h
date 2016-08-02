#ifndef CHUNK_SIZE_H
#define CHUNK_SIZE_H
#include <iostream>
#include <map>
#include <vector>
#include "chunks.h"

class ChunkSize {

public:
	typedef std::map<int, Chunks> chunkSizeList;
	
	void add(std::string chunk);
	chunkSizeList getAllChunks();
	Chunk &getChunk(std::string chunk);
private:
	chunkSizeList chunkSizes;
};

void ChunkSize::add(std::string sentence) {
	//find all chunks with given length of size

	//need to initalize chunkSizeList somehow..
	for(int i = 0; sentence[i] != '\0';) {

		int remaining = sentence.length() - i;

		std::string chunk_name = sentence.substr(i,1);
		int chunk_location = i;
		int chunk_length = chunk_name.length();

		Chunk chunk(chunk_name, chunk_location, 1);
		
		chunkSizeList::iterator got = chunkSizes.find(chunk_length);

		if (got == chunkSizes.end()) {

			Chunks chunks;
			chunks.add(chunk);
			std::pair<int, Chunks> current_chunk(chunk_length, chunks);
			chunkSizes.insert(current_chunk);

		} else {

			Chunks::chunkList &current_chunks = got->second.get();
			Chunks::chunkList::iterator cit = current_chunks.find(chunk_name);
			
			if (cit == current_chunks.end()) {
				got->second.add(chunk);
			} else {
				cit->second.incrementCount();
			}

		}

		i++;
	}

}

Chunk &ChunkSize::getChunk(std::string chunk) {
	Chunks &chunks = chunkSizes[chunk.length()];
	return chunks.getChunk(chunk);
}

ChunkSize::chunkSizeList ChunkSize::getAllChunks() {
	return chunkSizes;
}


#endif