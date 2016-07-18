#include <iostream>
#include <unordered_map>
#include <vector>
#include <iterator> 

int main(int argc, char* argv[])
{
	std::unordered_map<std::string, std::string> alphabet;
	alphabet = {\
		{"α","a"},\
		{"β","b"},\
		{"γ","y"},\
		{"δ","s"},\
		{"ε","e"},\
		{"ς","c"},\
		{"ζ","z"},\
		{"η","n"},\
		{"θ","o"},\
		{"ι","i"},\
		{"κ","k"},\
		{"λ","μ"},\
		{"ν","v"},\
		{"ξ","e"},\
		{"ό","o"},\
		{"π","n"},\
		{"σ","o"},\
		{"ς","c"},\
		{"τ","t"},\
		{"υ","v"},\
		{"φ","f"},\
		{"χ","x"},\
		{"ψ","y"},\
		{"ω","w"}\
	};

	std::string str(argv[1]);

	for (unsigned i=0; i<str.length(); ++i)
  {
    std::cout << str.at(i);
  }
	// std::cout << str << std::endl;

	// std::cout << alphabet[argv[1]] << std::endl;
} 

