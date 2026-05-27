#pragma once
#include <string>


class ScalarConverter
{
private:
	ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter& other) = delete;
	ScalarConverter operator=(const ScalarConverter& other) = delete;
	~ScalarConverter() = delete;
public:
	static void convert(const std::string& str);
};

