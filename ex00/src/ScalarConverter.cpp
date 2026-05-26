#include  "ScalarConverter.hpp"
#include <iostream>

void printAllImpossible(){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

bool isChar(const std::string& str){
	if(str.length() == 1 &&  !std::isdigit(str[0]))
		return true;
	return false;;
}

bool isInt(const std::string& str){
	size_t i = 0;

	if(str[i] == '+' || str[i] == '-')
		i++;
	while((i < str.size()) && std::isdigit(str[i]))
		i++;
	if(i != str.size())
		return false;
	try{
		std::stoi(str);
	}
	catch(...){
		return false;
	}
	return true;
}

bool isFlaot(const std::string& str){
	size_t i = 0;
	int dot = 0;

	if(str[i] == '+' || str[i] == '-')
		i++;
	while(i < str.size() && (std::isdigit(str[i]) || str[i] == '.')){
		if(str[i] == '.')
			dot++;
		i++;
	}
	if(dot != 1 || i != str.size() - 1 || str[i] != 'f')
		return false;
	try{
		std::stof(str);
	}
	catch(...){
		return false;
	}
	return true;
}

bool isDouble(const std::string& str){
	size_t i = 0;
	int dot = 0;

	if(str[i] == '+' || str[i] == '-')
		i++;
	while(i < str.size() && (std::isdigit(str[i]) || str[i] == '.')){
		if(str[i] == '.')
			dot++;
		i++;
	}
	if(dot != 1 || i != str.size())
		return false;
	try{
		std::stod(str);
	}
	catch(...){
		return false;
	}
}



int	getType(const std::string& str){
	if(isChar(str))
		return 0;
	if(isInt(str))
		return 1;
	if(isFlaot(str))
		return 2;
	if(isDouble(str))
		return 3;
	if(isPsuedoFloat(str))
		return 4;
	if(isPsuedoDouble(str))
		return 5;
	return 69;
}


void ScalarConverter::convert(const std::string& str){
	if(str.empty()){
		printAllImpossible();
		return ;
	}

	int inputType = getType(str);


}