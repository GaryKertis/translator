#include "sentence.h"

Sentence::Sentence(std::string sentence) {
	trim(sentence);
	fullSentence = sentence;
	addChunk(sentence);
}

Sentence::Sentence(Alphabet alphabet) {
	fullSentence = alphabet.getUntranslatedString();
	trim(fullSentence);
	addChunk(alphabet);
}

std::string Sentence::getBestMatch() {
	return bestMatch;
}

void Sentence::setBestMatch(std::string match, std::vector<int> saveLocations) {
	bestMatch = match;
	bestMatchLocations = saveLocations;
}

std::vector<int> Sentence::getBestMatchLocations() {
	return bestMatchLocations;
}

std::string Sentence::getFullSentence() {
	return fullSentence;
}

std::string Sentence::getSignature() {
	return signature;
}

Chunk &Sentence::getChunk(std::string chunk) {
	chunkList::iterator got = chunks.find(chunk);
	if (got != chunks.end()) {
		return got->second;
	} else {
		throw std::domain_error("No chunk found!");
	}
}

bool Sentence::hasChunkLocation(std::string chunk, int location) {
	try {
		return getChunk(chunk).hasLocation(location);
	} catch (const std::domain_error& e) {
		return false;
	}
}

int Sentence::getChunkCount(std::string chunk) {
	return getChunk(chunk).getCount();
}

std::vector<int> Sentence::getChunkLocations(std::string chunk) {
	return getChunk(chunk).getLocations();
}

Sentence::chunkList Sentence::getChunks() {
	return chunks;
}


void Sentence::addChunk(std::string sentence) {
//find all chunks with given length of size
	for(int i = 0; sentence[i] != '\0';) {

		int remaining = sentence.length() - i;

		std::string chunk_name = sentence.substr(i,1);
		int chunk_location = i;
		int chunk_length = chunk_name.length();

		chunkList::iterator it = chunks.find(chunk_name);
		
		if (it == chunks.end()) {
			Chunk chunk(chunk_name, chunk_location, 1);
			std::pair<std::string, Chunk> current_chunk(chunk_name, chunk);
			chunks.insert(current_chunk);
		} else {
			it->second.incrementCount();
			it->second.addLocation(chunk_location);
		}
		i++;
	}
}

void Sentence::addChunk(Alphabet alphabet) {
//find all chunks with given length of size
	int location = 0;

	Alphabet::outputType letters = alphabet.getTranslation();

	for(Alphabet::outputType::iterator i = letters.begin(); i != letters.end(); i++) {
		for(Alphabet::letterType::iterator j = i->begin(); j != i->end(); j++) {

		 	std::string chunk_name = *j;
			int chunk_location = location;
			int chunk_length = chunk_name.length();

			chunkList::iterator it = chunks.find(chunk_name);
			
			if (it == chunks.end()) {
				Chunk chunk(chunk_name, chunk_location, 1);
				std::pair<std::string, Chunk> current_chunk(chunk_name, chunk);
				chunks.insert(current_chunk);
			} else {
				it->second.incrementCount();
				it->second.addLocation(chunk_location);
			}

		}
		location++;
	}
}


bool Sentence::checkChars(char v) {
	return v == ' ' || v == ',';
}

std::string Sentence::sign(std::string sentence) {
	sentence.erase(remove_if(sentence.begin(), sentence.end(), checkChars), sentence.end());
	return sentence;
}