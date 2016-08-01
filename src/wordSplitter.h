// This is start of the header guard.  SPLITTER_H can be any unique name.  By convention, we use the name of the header file.
#ifndef WORD_SPLITTER_H
#define WORD_SPLITTER_H
#include <vector>
#include <iostream>

//This function splits a line of text and turns it into an array of sentences.
std::vector<std::string> wordSplitter(std::string input, std::string delimiter)
{
	std::vector<std::string> result;
	size_t pos = 0;
	std::string token;
	while ((pos = input.find(delimiter)) != std::string::npos) {
	    token = input.substr(0, pos);
	    result.push_back(token);
	    input.erase(0, pos + delimiter.length());
	}
	if(input.length() > 0) {
		result.push_back(input);
	}
	return result;
}
// This is the end of the header guard
#endif