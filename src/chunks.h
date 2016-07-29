#ifndef CHUNKS_H
#define CHUNKS_H
#include <iostream>
#include <map>
#include <vector>

class Chunks {

public:
	typedef std::vector<std::string> chunkList;

	void add(std::string chunk);
	void remove(std::string chunk);
	chunkList get();
private:
	chunkList chunks;
};

Chunks::chunkList Chunks::get() {
	return chunks;
}

void Chunks::add(std::string chunk) {
	chunks.push_back(chunk);
}

void Chunks::remove(std::string chunk) {
	//remove chunk
}


#endif