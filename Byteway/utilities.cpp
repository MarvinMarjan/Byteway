#include <string>
#include <vector>

#include "utilities.hpp"

using namespace std;

vector<string> Utils::split(string source)
{
	vector<string> splited;
	string aux = "";

	for (int i = 0; i < source.size(); i++)
	{
		if (source[i] == ' ' || i + 1 >= source.size())
		{
			if (i + 1 >= source.size())
				aux += source[i];

			splited.push_back(aux);
			aux = "";
		}

		else
			aux += source[i];
	}

	return splited;
}