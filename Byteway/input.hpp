#pragma once

#include <string>
#include <vector>

class Input
{
public:
	std::vector<std::string> get(); // return the getline splited
	void set(std::vector<std::string> source); // set this->command and this->args

	std::string command;
	std::vector<std::string> args;

	bool abort;
};