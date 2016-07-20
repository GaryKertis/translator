#ifndef CHUNKS_H
#define CHUNKS_H
#include <iostream>
#include <unordered_map>
#include <vector>

class Chunks {
public:
	std::unordered_map<int, std::vector<std::string>> items;
	void add(std::string chunk);
	void list();
private:
	void addSmallChunk(std::string smallChunk);

};

void Chunks::addSmallChunk(std::string smallChunk) {
	int len = smallChunk.length();
	std::unordered_map<int,std::vector<std::string>>::iterator got = items.find(len);
	if (got == items.end()) {
			std::vector<std::string> chunks;
			chunks.push_back(smallChunk);
			std::pair<int, std::vector<std::string>> current_chunk(len, chunks);
			items.insert(current_chunk);
		} else {
			got->second.push_back(smallChunk);
		}
}

void Chunks::add(std::string chunk) {
	for(int i = 0; chunk[i] != '\0';) {

		for(int j = 1; j <= chunk.length();) {
			std::string smallChunk = chunk.substr(i,j);
			addSmallChunk(smallChunk);
			j++;
		}

		i++;
	}
}

void Chunks::list() {

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