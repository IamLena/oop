#pragma once
#include <exception>
#include <string>

class base_exception : public std::exception {
protected:
	std::string info;
public:
	base_exception(std::string file, std::string name, int line, std::string message) {
		info = "\x1B[31mERROR\033[0m\t\t\nfile: " + file + "\nclass: " + name + "\nline: " + std::to_string(line) + "\n" + message + "\n";
	}
	std::string what() {
		return info;
	}
};

class size_exception : public base_exception {
public:
	size_exception(std::string file, std::string name, int line, std::string message) : 
		base_exception(file, name, line, message) {}
};

class memory_allocate_exception : public base_exception {
public:
	memory_allocate_exception (std::string file, std::string name, int line, std::string message) :
		base_exception(file, name, line, message) {}
};