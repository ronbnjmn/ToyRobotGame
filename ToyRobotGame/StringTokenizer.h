#pragma once

#include <string>
#include <vector>

// StringTokenizer splits a delimiter-separated string into a vector of strings.

class StringTokenizer
{
public:
	StringTokenizer(const std::string& string, const std::string& delimiter = " ");
	const std::string& operator[](size_t index) const;
	size_t count() const;

private:
	std::vector<std::string> tokens;
};
