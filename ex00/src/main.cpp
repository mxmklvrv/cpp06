#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char** av){
	if(ac != 2){
		std::cerr << "error: usage: ./ScalarConverter <value>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(std::string(av[1]));
	return 0;

}