#include <iostream>
#include <string>
#include <vector>

#include "utilities.hpp"
#include "input.hpp"

using namespace std;

vector<string> Input::get()
{
	string buff;
	getline(cin, buff);

	vector<string> full = Utils::split(buff);

	return full;
}

void Input::set(vector<string> source)
{
	if (source.size())
	{
		this->command = source[0];
		source.erase(source.begin());
		this->args = source;

		if (command == ".exit")
			this->abort = true;

		else
			this->abort = false;
	}

	else
		this->set({""});
}