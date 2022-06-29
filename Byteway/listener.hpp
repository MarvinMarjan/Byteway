#pragma once

#include <string>
#include <vector>

#include "repository.hpp"

class Repository; // Repository definition

// Listener is a friend class of Repository 
class Listener
{
public:
	void add(Repository rep); // adds a new repository to this->listeners

	bool update(Repository rep);

	Repository get(std::string name); // return a specified repository
	std::vector<Repository> get_all(); // return all repositorys in this->listeners

	int find(std::string name); // return the index of a specified repository
	int find(Repository name); // return the index of a specified repository

private:
	std::vector<Repository> listeners;
	std::vector<Repository> modified;
};