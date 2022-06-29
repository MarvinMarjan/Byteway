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
	void add_mod(Repository rep);

	void remove(Repository rep); // remove a this->listeners repository
	void remove_mod(Repository rep); // remove a this->modified repository

	bool update(Repository rep); // check if a repository is changed

	Repository get(std::string name); // return a specified repository
	std::vector<Repository> get_all(); // return all repositorys in this->listeners

	Repository get_mod(std::string name); // return a specified repository
	std::vector<Repository> get_all_mod(); // return all repositorys in this->listeners

	std::vector<Repository>::iterator itr_find(std::string name); // return the iterator of a this->listeners repository
	std::vector<Repository>::iterator itr_find(Repository rep); // return the iterator of a this->listeners repository

	std::vector<Repository>::iterator itr_find_mod(std::string name); // return the iterator of a this->listeners repository
	std::vector<Repository>::iterator itr_find_mod(Repository rep); // return the iterator of a this->listeners repository


	int find(std::string name); // return the index of a specified repository
	int find(Repository rep); // return the index of a specified repository

	int find_mod(std::string name); // return the index of a specified repository
	int find_mod(Repository rep); // return the index of a specified repository

private:
	std::vector<Repository> listeners;
	std::vector<Repository> modified;
};