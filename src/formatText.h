#ifndef FORMAT_TEXT_H
#define FORMAT_TEXT_H

#include <vector>
#include <algorithm>

void format(std::string sentence, std::vector<int> saveLocations) {

	char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
	char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };
	for(int i = 0; sentence[i] != '\0';) {
		bool exists = std::find(std::begin(saveLocations), std::end(saveLocations), i) != std::end(saveLocations);
		
		if (exists) {
			std::cout<<blue;
		} else {
			std::cout<<normal;
		}

		std::cout<<sentence[i];
		i++;
	}

	std::cout<<normal<<std::endl;

}

#endif