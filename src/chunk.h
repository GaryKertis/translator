#ifndef CHUNK_H
#define CHUNK_H
#include <iostream>
#include <vector>
#include <algorithm>

class Chunk {

public:
	std::vector<int> getLocations();
	int getCount();
	std::string getName();
	bool hasLocation(int location);
	void incrementCount();
	void addLocation(int location);
	Chunk(std::string chunk, int location, int count);
private:
	std::vector<int> m_locations;
	int m_count = 1;
	std::string m_chunk;
};


#endif