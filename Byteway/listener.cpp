#include <string>
#include <vector>

#include "repository.hpp"
#include "listener.hpp"

using namespace std;

void Listener::add(Repository rep)
{
	this->listeners.push_back(rep);
}

void Listener::add_mod(Repository rep)
{
	this->modified.push_back(rep);
}

void Listener::remove(Repository rep)
{
	this->listeners.erase(this->itr_find(rep));
}

void Listener::remove_mod(Repository rep)
{
	this->modified.erase(this->itr_find_mod(rep));
}

bool Listener::update(Repository rep)
{
	if (this->listeners[this->find(rep)].last_ent != rep.get_ent())
		return true;

	else
		return false;
}

Repository Listener::get(string name)
{
	return this->listeners[this->find(name)];
}

vector<Repository> Listener::get_all()
{
	return this->listeners;
}

Repository Listener::get_mod(string name)
{
	return this->modified[this->find(name)];
}

vector<Repository> Listener::get_all_mod()
{
	return this->modified;
}

vector<Repository>::iterator Listener::itr_find(Repository rep)
{
	for (auto itr = this->listeners.begin(); itr != this->listeners.end(); itr++)
		if (itr->name == rep.name)
			return itr;

	return vector<Repository>::iterator();
}

vector<Repository>::iterator Listener::itr_find(string name)
{
	for (auto itr = this->listeners.begin(); itr != this->listeners.end(); itr++)
		if (itr->name == name)
			return itr;

	return vector<Repository>::iterator();
}

vector<Repository>::iterator Listener::itr_find_mod(Repository rep)
{
	for (auto itr = this->modified.begin(); itr != this->modified.end(); itr++)
		if (itr->name == rep.name)
			return itr;

	return vector<Repository>::iterator();
}

vector<Repository>::iterator Listener::itr_find_mod(string name)
{
	for (auto itr = this->modified.begin(); itr != this->modified.end(); itr++)
		if (itr->name == name)
			return itr;

	return vector<Repository>::iterator();
}

int Listener::find(string name)
{
	for (int i = 0; i < this->listeners.size(); i++)
		if (this->listeners[i].name == name)
			return i;

	return -1;
}

int Listener::find(Repository rep)
{
	for (int i = 0; i < this->listeners.size(); i++)
		if (this->listeners[i].name == rep.name)
			return i;

	return -1;
}

int Listener::find_mod(string name)
{
	for (int i = 0; i < this->modified.size(); i++)
		if (this->modified[i].name == name)
			return i;

	return -1;
}

int Listener::find_mod(Repository rep)
{
	for (int i = 0; i < this->modified.size(); i++)
		if (this->modified[i].name == rep.name)
			return i;

	return -1;
}