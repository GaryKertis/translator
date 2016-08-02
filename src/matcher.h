#ifndef MATCHER_H
#define MATCHER_H
#include "sentence.h"
#include <iostream>
#include <vector>
#include <map>
#include "formatText.h"

class Matcher {
public:
	void match(Sentence &input, Sentence &source, int chunkLength);
private:
	int counter = 0;
	int highestMatches = 0;
};

void Matcher::match(Sentence &input, Sentence &source, int chunkLength) {

	Sentence::chunkList inputChunks = input.getChunks();

	    int totalChunksMatched = 0;
	   	std::vector<int> matchLocations;

	    for(Sentence::chunkList::iterator ic = inputChunks.begin(); ic != inputChunks.end(); ic++) {

	        int sourceMatches = source.getChunkLocations(ic->first);
	        int inputMatches = ic->second.getLocation();

	    	if (sourceMatches != 0 && sourceMatches == inputMatches) {

				totalChunksMatched++;
				matchLocations.push_back(sourceMatches);
	    	} 


			if (totalChunksMatched > highestMatches) {

				highestMatches = totalChunksMatched;

				format(source.getFullSentence(), matchLocations);
				format(input.getFullSentence(), matchLocations);
				
				input.setBestMatch(source.getFullSentence());

			}

	    }

}

#endif