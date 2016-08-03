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
	int addLetter(std::string symbol);
	alphabetType getAlphabet();
	alphabetType getTranslation();
	Alphabet();
private:
	alphabetType m_translation;
	alphabetType m_alphabet;
};

#endif