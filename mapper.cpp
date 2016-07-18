#include "splitter.h"
#include <iostream>
#include <unistd.h>

void readOption(std::string input) {
    for(auto const& value: splitter(input, ".")) 
	{
		std::cout << value << std::endl;
	}
}

int main(int argc, char* argv[])
{

	int opt;

    while ((opt = getopt(argc, argv, "i:o:")) != -1) {
        switch (opt) {
        case 'i':
        	readOption(optarg);
            break;
        case 'o':
        	readOption(optarg);
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


