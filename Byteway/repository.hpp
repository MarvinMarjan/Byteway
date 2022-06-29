#pragma once

#include <string>

#include "listener.hpp"

class Repository
{
public:
	friend Listener;

	Repository(std::string name, std::string path); // create a new repository object

	std::vector<std::string> get_ent(); // return the entries of this->path

	void set_name(std::string name); // set this->name
	void set_path(std::string path); // set this->path

	std::string get_name(); // return this->name
	std::string get_path(); // return this->path

private:
	std::string name;
	std::string path;

	std::vector<std::string> last_ent;
};