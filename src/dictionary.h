#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "sentence.h"
#include <iostream>
#include <vector>

class Dictionary {
public:
	typedef std::vector<Sentence> sentenceList;
	sentenceList items;
	int current_id;
	void add(sentenceList sentences);
};

void Dictionary::add(sentenceList sentences) {
	current_id++;
	items.insert( items.end(), sentences.begin(), sentences.end() );
}

#endif