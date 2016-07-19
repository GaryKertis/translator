#include "splitter.h"
#include "dictionary.h"
#include <iostream>
#include <unistd.h>
#include <fstream>

Dictionary dictionary;

int readFile(std::string fileName) {
  std::string line;
  std::ifstream myfile (fileName);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      dictionary.add(splitter(line, "."));
    }
    myfile.close();
  } else {
    std::cerr << "Unable to open file " + fileName << std::endl; 
    exit(EXIT_FAILURE);
  } 

  std::cout << dictionary.items[124335].fullSentence << std::endl;
}


int main(int argc, char* argv[])
{

	int opt;

    while ((opt = getopt(argc, argv, "i:o:")) != -1) {
        switch (opt) {
        case 'i':
        	readFile(optarg);
            break;
        case 'o':
        	readFile(optarg);
            break;
        default: /* '?' */
            fprintf(stderr, "Usage: %s [-i] input [-o] output\n",
                    argv[0]);
            exit(EXIT_FAILURE);
        }
    }

   // if (optind >= argc) {
   //      fprintf(stderr, "Expected argument after options\n");
   //      exit(EXIT_FAILURE);
   //  }

   /* Other code omitted */

   exit(EXIT_SUCCESS);

} 

