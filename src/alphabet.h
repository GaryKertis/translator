#ifndef ALPHABET_H
#define ALPHABET_H
#include <iostream>
#include <map>
#include "trim.h"
#include "chunk.h"

class Alphabet {
public:
	typedef std::vector<std::string> letterType;
	typedef std::map<std::string, letterType> alphabetType;
	typedef std::vector<letterType> outputType;
	int addLetter(std::string symbol);
	alphabetType getAlphabet();
	outputType getTranslation();
	std::string getUntranslatedString();
	void setUntranslatedString(std::string);
	Alphabet();
private:
	outputType m_translation;
	alphabetType m_alphabet;
	std::string m_untranslated_string;
};

#endif