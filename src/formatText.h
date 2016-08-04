#ifndef FORMAT_TEXT_H
#define FORMAT_TEXT_H

#include <vector>
#include <algorithm>

std::string format(std::string sentence, std::vector<int> saveLocations) {
	std::string result = "";

	char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
	char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };
	for(int i = 0; sentence[i] != '\0';) {
		bool exists = std::find(std::begin(saveLocations), std::end(saveLocations), i) != std::end(saveLocations);
		
		if (exists) {
			result.append(blue);
		} else {
			result.append(normal);
		}
		std::string thisChar(1, sentence[i]);
		result.append(thisChar);
		i++;
	}

	result.append(normal);
	return result;

}

#endif