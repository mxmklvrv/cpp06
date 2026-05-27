#include  "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>


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
	return true;
}

bool isPsuedoFloat(const std::string& str){
	return (str == "-inff" || str == "inff" || str == "nanf");
}

bool isPsuedoDouble(const std::string& str){
	return (str == "-inf" || str == "inf" || str == "nan");
}

int afterDotDigits(const std::string& str){
	size_t dot = str.find('.');
	if(dot == std::string::npos)
		return 1;
	size_t i = dot + 1;
	int res = 0;
	while(i < str.size() && std::isdigit(str[i])){
		i++;
		res++;
	}
	return res == 0 ? 1 : res;
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

void printChar(const std::string& str){
	char c = str[0];
	if(std::isprint(c))
		std::cout << "char: " << "'" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void toChar(const std::string& str){
	double temp;

	try{
		temp = std::stod(str);
	}
	catch(...){
		std::cout << "char: impossible" << std::endl;
		return;
	}
	if(std::isnan(temp) || std::isinf(temp) || temp < 0.0 || temp > 127.0){
		std::cout << "char: impossible" << std::endl;
		return;
	}
	if(temp < 32.0 || temp == 127.0){
		std::cout << "char: Non displayable" << std::endl;
		return;
	}
	std::cout << "char: " << "'" << static_cast<char>(temp) << "'" << std::endl;

}

void toInt(const std::string& str){
	double temp;

	try{
		temp = std::stod(str);
	}
	catch(...){
		std::cout << "int: impossible" << std::endl;
		return;
	}
	if(std::isnan(temp) || std::isinf(temp)){
		std::cout << "int: impossible" << std::endl;
		return;
	}
	if(temp > std::numeric_limits<int>::max() || temp < std::numeric_limits<int>::min()){
		std::cout << "int: impossible" << std::endl;
		return;
	}
	std::cout << "int: " << static_cast<int>(temp) << std::endl;
}

void toFloat(const std::string& str, int precision){
	std::cout << "float: ";
	try
	{
		float temp = stof(str);
		std::cout << std::fixed << std::setprecision(precision);
		std::cout << temp << "f" << std::endl;
	}
	catch(...){
		std::cout << "impossible" << std::endl;
	}
}

void toDouble(const std::string& str, int precision){
	std::cout << "double: ";
	try{
		double temp = stod(str);
		std::cout << std::fixed << std::setprecision(precision) << temp << std::endl;
	}
	catch(...){
		std::cout << "impossible" << std::endl;
	}
}


void ScalarConverter::convert(const std::string& str){
	if(str.empty()){
		printAllImpossible();
		return ;
	}

	int inputType = getType(str);
	int precision = afterDotDigits(str);

	switch (inputType)
	{
	case 0:
		printChar(str);
		break;

	case 1:
		toChar(str);
		toInt(str);
		toFloat(str, precision);
		toDouble(str, precision);
		break;
	case 2:
		toChar(str);
		toInt(str);
		toFloat(str, precision);
		toDouble(str, precision);
		break;
	case 3:
		toChar(str);
		toInt(str);
		toFloat(str, precision);
		toDouble(str, precision);
		break;
	case 4:
		toChar(str);
		toInt(str);
		toFloat(str, precision);
		toDouble(str, precision);
		break;
	case 5:
		toChar(str);
		toInt(str);
		toFloat(str, precision);
		toDouble(str, precision);
		break;
	case 69:
		printAllImpossible();
		break;
	default:
		std::cout << "Sys error" << std::endl;
	}
}