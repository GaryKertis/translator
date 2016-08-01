#ifndef MATCHER_H
#define MATCHER_H
#include "sentence.h"
#include "matches.h"
#include <iostream>
#include <vector>
#include <map>

class Matcher {
public:
	void match(Sentence &input, Sentence source);
private:
	int counter = 0;
	int highestMatches = 0;
};

void Matcher::match(Sentence &input, Sentence source) {
	std::cout << "Currently matching " << source.getFullSentence() << std::endl;
	Words::wordList words = input.getWords();

	    int totalWordsMatched = 0;

	    for(auto const& word: words) {
	        
	        int chunkMatch = source.getChunkCount(word);  
	        //std::cout << "Looking at " << word << std::endl;
	    	if (chunkMatch > 0) {

				std::map<std::string,int>::iterator got = input.matches.find(source.getFullSentence());

				if (got == input.matches.end()) {
					std::pair<std::string, int> current_chunk(source.getFullSentence(), 1);
					input.matches.insert(current_chunk);
				} else {
					got->second = got->second + 1;
				}

				totalWordsMatched += chunkMatch;
	    	} 

				if (totalWordsMatched > highestMatches) {
					highestMatches = totalWordsMatched;
					input.setBestMatch(source.getFullSentence());
					std::cout << "HighestMatches " << highestMatches << std::endl;
					std::cout << "New Best match " << source.getFullSentence() << std::endl;
				}
				//std::cout << "Found " << chunkMatch << " matches " << word << " for length " << chunkLength << std::endl;

	    }

}

#endif