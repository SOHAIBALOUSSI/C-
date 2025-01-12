#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
    return *this;
}


enum e_type {
    INT,
    CHAR,
    FLOAT,
    DOUBLE,
    UNKOWN
}; 

bool    isFloat(const std::string& s) {
    if (s[s.length() - 1] != 'f') return false;
    

    int start = 0;
    if (s[0] == '-' || s[0] == '+') start = 1;
    std::string check = s.substr(0, s.size() - 1);
    return check.find_first_not_of("0123456789.", start) == std::string::npos;
}

bool    isInt(const std::string& s){
    int start = 0;
    if (s[0] == '-' || s[0] == '+') start = 1;
    return s.find_first_not_of("0123456789", start) == std::string::npos;
}

bool    isDouble(const std::string& s){
    return true;
}

e_type getType(const std::string& s) {
    if (s.size() == 1 && isalpha(s[0])) return CHAR;
    if (isInt(s)) return INT;
    if (isFloat(s)) return FLOAT;
    // if (isDouble(s)) return DOUBLE;
    return UNKOWN;
}


void    ScalarConverter::convert(const std::string& literal) {

    int dotCount = 0;
    if (literal.empty()) {
        throw std::runtime_error("invalid input");
    }
    for (int i=0; i< literal.size(); i++) {
        if (literal[i] == '.') dotCount++;
        if (dotCount > 1 || !isprint(literal[i])) throw std::runtime_error("invalid input");
    }

    e_type type = getType(literal);
    std::cout << type << "\n";
    if (type == INT) {
        long val = std::strtol(literal.c_str(), 0, 10);

        if (val > INT_MAX || val < INT_MIN) {
            throw std::runtime_error("overflow detected");
        }
        if (val > 255 || val < 0 || !isprint(val))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << static_cast<char>(val) << std::endl;
        std::cout << "int: " << static_cast<int>(val) << std::endl;
        std::cout << "float: " << static_cast<float>(val) <<  std::endl; 
        std::cout << "double: " << static_cast<double>(val) << std::endl;
    }
    else if (type == CHAR) {
        char val = literal[0];
        std::cout << "char: " << val << std::endl;
        std::cout << "int: " << static_cast<int>(val) << std::endl;
        std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl; 
        std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
    }
    else if (type == FLOAT) {
        float val = strtof(literal.c_str(), 0);
        bool zeroFract = literal.find(".0f") != std::string::npos;
        if (val > INT_MAX || val < INT_MIN) {
            throw std::runtime_error("overflow detected");
        }
        if (val > 255 || val < 0 || !isprint(val))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << static_cast<char>(val) << std::endl;
        std::cout << "int: " << static_cast<int>(val) << std::endl;
        if (zeroFract) {
            std::cout << "float: " << static_cast<float>(val) << ".0f" <<  std::endl; 
            std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
        }
        else {
            std::cout << "float: " << literal <<  std::endl; 
            std::cout << "double: " << static_cast<double>(val) << std::endl;
        }
    }
    else if (type == DOUBLE) {

    }
    else {
        throw std::runtime_error("UNKOWN type");
    }
}