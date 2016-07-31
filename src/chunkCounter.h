#ifndef CHUNK_COUNTER_H
#define CHUNK_COUNTER_H
#include <iostream>
#include <map>
#include <vector>
#include "chunks.h"

class ChunkCounter {

public:
	typedef std::map<std::string, int> chunkCountMap;
	typedef std::pair<std::string, int> chunkCountItem;
	
	int getCount(std::string chunk);
	void count(std::string sentence);
	chunkCountMap getAll();
private:
	chunkCountMap chunkCount;
};

void ChunkCounter::count(std::string sentence) {
	for(int i = 0; sentence[i] != '\0';) {

		int remaining = sentence.length() - i;

		for(int j = 1; j <= remaining;) {
			std::string chunk = sentence.substr(i,j);
			
				chunkCountMap::iterator existingChunk = chunkCount.find(chunk);

				if (existingChunk == chunkCount.end()) {
					chunkCountItem current_count(chunk, 1);
					chunkCount.insert(current_count);
				} else {
					existingChunk->second++;
				}

			j++;
		}

		i++;
	}

}

int ChunkCounter::getCount(std::string chunk) {
	chunkCountMap::iterator got = chunkCount.find(chunk);

	if (got != chunkCount.end()) {
		return got->second;
	}
	return 0;
}

ChunkCounter::chunkCountMap ChunkCounter::getAll() {
	return chunkCount;
}


#endif