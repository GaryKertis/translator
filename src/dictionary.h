#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "sentence.h"
#include <iostream>
#include <vector>

class Dictionary {
public:
	typedef std::vector<Sentence> sentenceList;
	sentenceList items;
	void add(sentenceList sentences);
	std::vector<Sentence> splitter(std::string input, std::string delimiter);
};

void Dictionary::add(sentenceList sentences) {
	items.insert( items.end(), sentences.begin(), sentences.end() );
}

Dictionary::sentenceList Dictionary::splitter(std::string input, std::string delimiter)
{
	std::vector<Sentence> result;
	size_t pos = 0;
	std::string token;
	while ((pos = input.find(delimiter)) != std::string::npos) {
	    token = input.substr(0, pos);
		Sentence sentence(token);
	    result.push_back(sentence);
	    input.erase(0, pos + delimiter.length());
	}
	if(input.length() > 0) {
		Sentence sentence(input);
		result.push_back(sentence);
	}
	return result;
}

#endif