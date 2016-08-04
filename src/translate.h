#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <iostream>
#include <unordered_map>
#include <string>
#include <bitset>
#include <cctype>
#include "alphabet.h"


Alphabet translate(std::string line) {
	Alphabet result;
	result.setUntranslatedString(line);
	for(int i = 0; line[i] != '\0';) {

		std::string input(1, line[i]);
		std::string input2(1,line[i+1]);
		std::string input3(1, line[i+2]);
		std::string thisChar;

		std::bitset<8> bites(input.c_str()[0]);

		if (bites[5] == 1 && bites[6] == 1 && bites[7] == 1) {
				input.append(input2);
				input.append(input3);
				i = i + 3;
		} else if (bites[6] == 1 && bites[7] == 1) {
				input.append(input2);
				i = i + 2;
		} 
		i = i + result.addLetter(input);
	}

	return result;

}

#endif