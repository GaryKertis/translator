#include "chunk.h"

int Chunk::getLocation() {
	return m_location;
}

int Chunk::getCount() {
	return m_count;
}

void Chunk::updateLocation(int location) {
	m_location = location;
}

void Chunk::incrementCount() {
	m_count = m_count + 1;
}

std::string Chunk::getName() {
	return m_chunk;
}