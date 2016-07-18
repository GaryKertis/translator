#include "splitter.h"
#include <iostream>
#include <unistd.h>
#include <fstream>

void readOption(std::string input) {
    for(auto const& value: splitter(input, ".")) 
	{
		//std::cout << value << std::endl;
	}
}

int readFile(std::string fileName) {
  std::string line;
  std::ifstream myfile (fileName);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      readOption(line);
    }
    myfile.close();
  }

  else std::cerr << "Unable to open file " + fileName << std::endl; 

  exit(EXIT_FAILURE);
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


