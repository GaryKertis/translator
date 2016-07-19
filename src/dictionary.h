#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "definition.h"
#include <iostream>
#include <vector>

class Dictionary {
public:
	std::vector<Definition> items;
	int current_id;
	void add(std::vector<Definition> definitions);
};

void Dictionary::add(std::vector<Definition> definitions) {
	current_id++;
	items.insert( items.end(), definitions.begin(), definitions.end() );
	std::cout << current_id << std::endl;
}

#endif