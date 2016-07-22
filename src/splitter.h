// This is start of the header guard.  SPLITTER_H can be any unique name.  By convention, we use the name of the header file.
#ifndef SPLITTER_H
#define SPLITTER_H

#include "sentence.h"
#include <vector>
#include <iostream>

//This function splits a line of text and turns it into an array of sentences.
std::vector<Sentence> splitter(std::string input, std::string delimiter)
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
// This is the end of the header guard
#endif