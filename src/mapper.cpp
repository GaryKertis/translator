#include "splitter.h"
#include "dictionary.h"
#include "translate.h"
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
  std::string translatedLine = translate(line);
  inputText.add(splitter(translatedLine, "."));
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


  std::cout << inputText.items[10].fullSentence << std::endl;
  inputText.items[10].chunks.list();

   // if (optind >= argc) {
   //      fprintf(stderr, "Expected argument after options\n");
   //      exit(EXIT_FAILURE);
   //  }

   /* Other code omitted */

   exit(EXIT_SUCCESS);

} 

