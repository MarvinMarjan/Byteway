#pragma once

#include <string>

#include "listener.hpp"

class Repository
{
public:
	friend Listener;

	Repository(std::string name, std::string path);

	std::vector<std::string> get_ent();

	void set_name(std::string name);
	void set_path(std::string path);

	std::string get_name();
	std::string get_path();

private:
	std::string name;
	std::string path;

	std::vector<std::string> last_ent;
};