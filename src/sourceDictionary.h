#ifndef SOURCE_DICTIONARY_H
#define SOURCE_DICTIONARY_H
#include "sentence.h"
#include "sourceLine.h"
#include <iostream>
#include <vector>

class SourceDictionary {
public:
	typedef std::vector<SourceLine> sourceLineList;
	sourceLineList items;
	void add(sourceLineList sourceLines);
	std::vector<SourceLine> splitter(std::string input, std::string delimiter);
};


void SourceDictionary::add(sourceLineList sourceLines) {
	items.insert( items.end(), sourceLines.begin(), sourceLines.end() );
}

SourceDictionary::sourceLineList SourceDictionary::splitter(std::string input, std::string delimiter)
{
	std::vector<SourceLine> result;
	size_t pos = 0;
	std::string token;
	while ((pos = input.find(delimiter)) != std::string::npos) {
	    token = input.substr(0, pos);
		SourceLine sourceLine(token);
	    result.push_back(sourceLine);
	    input.erase(0, pos + delimiter.length());
	}
	if(input.length() > 0) {
		SourceLine sourceLine(input);
		result.push_back(sourceLine);
	}
	return result;
}

#endif