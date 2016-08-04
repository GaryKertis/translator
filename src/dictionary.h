#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "sentence.h"
#include <iostream>
#include <vector>

class Dictionary {
public:
	typedef std::vector<Sentence> sentenceList;
	sentenceList items;
	void add(sentenceList);
	void add(Sentence);
};

void Dictionary::add(sentenceList sentences) {
	items.insert( items.end(), sentences.begin(), sentences.end() );
}

void Dictionary::add(Sentence sentence) {
	items.push_back(sentence);
}

#endif