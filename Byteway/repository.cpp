#include <dirent.h>
#include <string>
#include <vector>

#include "repository.hpp"
#include "path.hpp"

using namespace std;

Repository::Repository(string name, string path)
{
	this->set_name(name);

	if (Path::exist(path))
	{
		this->set_path(path);
		this->last_ent = this->get_ent();
	}

	else
		this->set_path("_invalid_path");
}

vector<string> Repository::get_ent()
{
	DIR* dir = opendir(this->path.c_str());
	vector<string> ents;

	struct dirent* ent{};

	while ((ent = readdir(dir)) != NULL)
		ents.push_back(ent->d_name);
	
	return ents;
}

void Repository::set_name(string name)
{
	this->name = name;
}

void Repository::set_path(string path)
{
	this->path = path;
}

string Repository::get_name()
{
	return this->name;
}

string Repository::get_path()
{
	return this->path;
}