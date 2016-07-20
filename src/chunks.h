#ifndef CHUNKS_H
#define CHUNKS_H
#include <iostream>
#include <unordered_map>
#include <vector>

class Chunks {

public:
	typedef std::vector<std::string> chunkList;
	typedef std::unordered_map<int, chunkList> chunkSizeList;

	chunkSizeList items;
	void add(std::string chunk);
	chunkList list(int len);
	void listAll();
private:
	void addSmallChunk(std::string smallChunk);

};

void Chunks::addSmallChunk(std::string smallChunk) {
	int len = smallChunk.length();
	chunkSizeList::iterator got = items.find(len);
	if (got == items.end()) {
			chunkList chunks;
			chunks.push_back(smallChunk);
			std::pair<int, chunkList> current_chunk(len, chunks);
			items.insert(current_chunk);
		} else {
			got->second.push_back(smallChunk);
		}
}

void Chunks::add(std::string chunk) {
	for(int i = 0; chunk[i] != '\0';) {

		int remaining = chunk.length() - i;

		for(int j = 1; j <= remaining;) {
			std::string smallChunk = chunk.substr(i,j);
			addSmallChunk(smallChunk);
			j++;
		}

		i++;
	}
}

Chunks::chunkList Chunks::list(int len) {
	return items[len];
}

void Chunks::listAll() {

	for(auto &i : items) {
			std::cout << i.first << std::endl;
		for(auto const& value: i.second) {
     		std::cout << value;
     		std::cout << ", ";
     	}
     	std::cout << std::endl;
     	std::cout << std::endl;
     	std::cout << std::endl;
	}
}


#endif