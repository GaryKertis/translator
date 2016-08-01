#include "dictionary.h"
#include "sourceDictionary.h"
#include "translate.h"
#include "matches.h"
#include "matcher.h"
#include <iostream>
#include <unistd.h>
#include <fstream>

SourceDictionary sourceText;
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
  std::string translatedLine = translate(line);
  inputText.add(inputText.splitter(translatedLine, "."));
}

void addLine(std::string line) {
  sourceText.add(sourceText.splitter(line, "."));
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
  matcher.match(inputText.items[0], *it, 3);
  }
  matcher.resetMatches();
  for (auto it = sourceText.items.begin(); it != sourceText.items.end(); ++it) {
  matcher.match(inputText.items[0], *it, 4);
  }
  // std::map<std::string,int>::iterator got = inputText.items[0].matches.find(it->getFullSentence());
  
  // if (got != inputText.items[0].matches.end()) {
  //   std::cout << got->first << std::endl << got->second << std::endl;
  // }
  std::cout << "English " << inputText.items[0].getFullSentence() << std::endl;
  std::cout << " Best match = " << inputText.items[0].getBestMatch() << std::endl;

  for (auto it = inputText.items[0].matches.begin(); it != inputText.items[0].matches.end(); ++it) {
    std::cout << "Other matches: " << it->first << " " << it->second << std::endl;
  }

  //std::cout << inputText.items[10].fullSentence << std::endl;
  //inputText.items[10].chunks.listAll();

   // if (optind >= argc) {
   //      fprintf(stderr, "Expected argument after options\n");
   //      exit(EXIT_FAILURE);
   //  }

   /* Other code omitted */

   exit(EXIT_SUCCESS);

} 

