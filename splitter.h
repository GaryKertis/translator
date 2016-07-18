// This is start of the header guard.  SPLITTER_H can be any unique name.  By convention, we use the name of the header file.
#ifndef SPLITTER_H
#define SPLITTER_H
 
#include <vector>
#include <iostream>

// This is the content of the .h file, which is where the declarations go
std::vector<std::string> splitter(std::string input, std::string delimiter)
{
	std::vector<std::string> result;
	size_t pos = 0;
	std::string token;
	while ((pos = input.find(delimiter)) != std::string::npos) {
	    token = input.substr(0, pos);
	    result.push_back(token);
	    input.erase(0, pos + delimiter.length());
	}
	result.push_back(input);
	return result;
}
// This is the end of the header guard
#endif