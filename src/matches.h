#ifndef MATCHES_H
#define MATCHES_H
#include "dictionary.h"
#include "sentence.h"
#include <iostream>
#include <vector>
#include <iterator>

class Matches {
public:
	Dictionary matches;
	void remove(int getPosition);
	Matches(Dictionary sourceText);
};

Matches::Matches(Dictionary sourceText) {
	matches = sourceText;
}

void Matches::remove(int getPosition) {
	//
}


#endif