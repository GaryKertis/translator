#include "chunk.h"

Chunk::Chunk(std::string chunk, int location, int count) {
	m_chunk = chunk;
	m_locations.push_back(location);
	m_count = count; 
}

bool Chunk::hasLocation(int location) {
	return std::find(m_locations.begin(), m_locations.end(), location) != m_locations.end();
}

std::vector<int> Chunk::getLocations() {
	return m_locations;
}

int Chunk::getCount() {
	return m_count;
}

void Chunk::incrementCount() {
	m_count = m_count + 1;
}

void Chunk::addLocation(int location) {
	m_locations.push_back(location);
}

std::string Chunk::getName() {
	return m_chunk;
}