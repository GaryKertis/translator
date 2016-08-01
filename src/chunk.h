#ifndef CHUNK_H
#define CHUNK_H
#include <iostream>
#include <map>
#include <vector>

class Chunk {

public:
	int getLocation();
	int getCount();
	std::string getName();
	Chunk(std::string chunk, int location, int count) : m_chunk(chunk), m_location(location), m_count(count) {}

private:
	int m_location;
	int m_count;
	std::string m_chunk;
};

int Chunk::getLocation() {
	return m_location;
}

int Chunk::getCount() {
	return m_count;
}

std::string Chunk::getName() {
	return m_chunk;
}

#endif