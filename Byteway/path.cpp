#include <dirent.h>
#include <string>

#include "path.hpp"

using namespace std;

bool Path::exist(string path)
{
	DIR* dir = opendir(path.c_str());

	if (dir)
		return true;

	else
		return false;
}