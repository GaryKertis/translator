#ifndef MATCHER_H
#define MATCHER_H
#include "sentence.h"
#include <iostream>
#include <vector>

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
   	std::vector<int> saveLocations;

    for(Sentence::chunkList::iterator ic = inputChunks.begin(); ic != inputChunks.end(); ic++) {
  		
   		std::vector<int> matchLocations = ic->second.getLocations();
        for (int i = 0; i < ic->second.getCount(); i++) {

	    	if (source.hasChunkLocation(ic->first, matchLocations[i])) {
				totalChunksMatched++;
				saveLocations.push_back(matchLocations[i]);
	    	}

		}	

		if (totalChunksMatched > highestMatches) {
			
			highestMatches = totalChunksMatched;
			
			input.setBestMatch(source.getFullSentence(), saveLocations);

		}

    }

}

#endif