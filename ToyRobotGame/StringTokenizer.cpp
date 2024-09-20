#include "StringTokenizer.h"

#include <string>
#include <vector>

StringTokenizer::StringTokenizer(const std::string& string, const std::string& delimiter)
{
	size_t tokenPos = 0;
	size_t delimiterPos = 0;
	while ((delimiterPos = string.find(delimiter, tokenPos)) != std::string::npos)
	{
		tokens.push_back(string.substr(tokenPos, delimiterPos));
		tokenPos = delimiterPos + delimiter.length();
	}
	tokens.push_back(string.substr(tokenPos));
}

std::string& StringTokenizer::operator[](size_t index)
{
	return tokens[index];
}

size_t StringTokenizer::count()
{
	return tokens.size();
}
