#include "splitter.h"
#include "dictionary.h"
#include "translate.h"
#include "matcher.h"
#include "sentence.h"
#include "formatText.h"
#include <iostream>
#include <unistd.h>
#include <fstream>

Dictionary sourceText;
Dictionary inputText;

int readFile(std::string fileName, void (*callback)(std::string)) {
  std::string line;
  std::ifstream myfile (fileName);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      (*callback)(line);
    }
    myfile.close();
  } else {
    std::cerr << "Unable to open file " + fileName << std::endl; 
    exit(EXIT_FAILURE);
  } 
}

void translateLine(std::string line) {
  Alphabet translatedLine = translate(line);
  Sentence sentence(translatedLine);
  inputText.add(sentence);
}

void addLine(std::string line) {
  sourceText.add(splitter(line, "."));
}

int main(int argc, char* argv[])
{

	int opt;

    while ((opt = getopt(argc, argv, "i:s:")) != -1) {
        switch (opt) {
        case 'i':
        	readFile(optarg, translateLine);
            break;
        case 's':
        	readFile(optarg, addLine);
            break;
        default: /* '?' */
            fprintf(stderr, "Usage: %s [-i] input [-s] output\n",
                    argv[0]);
            exit(EXIT_FAILURE);
        }
    }

  //Matches matches(sourceText);

  //populate initial sentence list.
  Matcher matcher;

  for (auto it = sourceText.items.begin(); it != sourceText.items.end(); ++it) {
      matcher.match(inputText.items[0], *it, 1);
  }

  std::cout<<inputText.items[0].getFullSentence()<<std::endl;
  format(inputText.items[0].getBestMatch(), inputText.items[0].getBestMatchLocations());

   // if (optind >= argc) {
   //      fprintf(stderr, "Expected argument after options\n");
   //      exit(EXIT_FAILURE);
   //  }

   /* Other code omitted */

   exit(EXIT_SUCCESS);

} 

