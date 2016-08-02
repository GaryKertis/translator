#ifndef CHUNK_H
#define CHUNK_H
#include <iostream>

class Chunk {

public:
	int getLocation();
	int getCount();
	std::string getName();
	void incrementCount();
	void updateLocation(int location);
	Chunk(std::string chunk, int location, int count) : m_chunk(chunk), m_location(location), m_count(count) {}; 
private:
	int m_location;
	int m_count;
	std::string m_chunk;
};


#endif