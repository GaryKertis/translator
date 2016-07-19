// This is start of the header guard.  SPLITTER_H can be any unique name.  By convention, we use the name of the header file.
#ifndef SPLITTER_H
#define SPLITTER_H

#include "definition.h"
#include <vector>
#include <iostream>

//This function splits a line of text and turns it into an array of definitions.
std::vector<Definition> splitter(std::string input, std::string delimiter)
{
	std::vector<Definition> result;
	size_t pos = 0;
	std::string token;
	while ((pos = input.find(delimiter)) != std::string::npos) {
	    token = input.substr(0, pos);
		Definition definition(token);
	    result.push_back(definition);
	    input.erase(0, pos + delimiter.length());
	}
	if(input.length() > 0) {
		Definition definition(input);
		result.push_back(definition);
	}
	return result;
}
// This is the end of the header guard
#endif