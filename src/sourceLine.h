#ifndef SOURCE_LINE_H
#define SOURCE_LINE_H
#include <iostream>
#include <map>
#include <vector>
#include "trim.h"
#include "chunkCounter.h"

class SourceLine {
public:

	std::string getFullSentence();
	std::string getSignature();
	int getLength();
	int getChunkCount(std::string chunk);
	SourceLine(std::string sentence);

private:
	std::string fullSentence;
	std::string signature;
	ChunkCounter chunkCounter;
	std::string sign(std::string sentence);
	static bool checkChars(char v);
};

SourceLine::SourceLine(std::string sentence) {
	trim(sentence);
	signature = sign(sentence);
	fullSentence = sentence;
	chunkCounter.count(sentence);
}

int SourceLine::getLength() {
	return signature.length();
}

std::string SourceLine::getFullSentence() {
	return fullSentence;
}

std::string SourceLine::getSignature() {
	return signature;
}

int SourceLine::getChunkCount(std::string chunk) {
	return chunkCounter.getCount(chunk);
}

bool SourceLine::checkChars(char v) {
	return v == ' ' || v == ',';
}

std::string SourceLine::sign(std::string sentence) {
	sentence.erase(remove_if(sentence.begin(), sentence.end(), checkChars), sentence.end());
	return sentence;
}

#endif