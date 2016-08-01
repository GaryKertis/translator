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
	Chunks getChunk(int i);
private:
	chunkSizeList chunkSizes;
};

void ChunkSize::add(std::string sentence) {
	//find all chunks with given length of size

	//need to initalize chunkSizeList somehow..
	for(int i = 0; sentence[i] != '\0';) {

		int remaining = sentence.length() - i;

		for(int j = 1; j <= remaining;) {
			std::string chunk_name = sentence.substr(i,j);
			int chunk_location = i;
			int chunk_length = chunk_name.length();

			Chunk chunk(chunk_name, chunk_location, chunk_length);
			
				chunkSizeList::iterator got = chunkSizes.find(chunk_length);

				if (got == chunkSizes.end()) {

					Chunks chunks;
					chunks.add(chunk);
					std::pair<int, Chunks> current_chunk(chunk_length, chunks);
					chunkSizes.insert(current_chunk);

				} else {

					got->second.add(chunk);

				}
			j++;
		}

		i++;
	}

}

Chunks ChunkSize::getChunk(int i) {
	return chunkSizes[i];
}

ChunkSize::chunkSizeList ChunkSize::getAllChunks() {
	return chunkSizes;
}


#endif