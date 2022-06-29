#include <string>
#include <vector>

#include "repository.hpp"
#include "listener.hpp"

using namespace std;

void Listener::add(Repository rep)
{
	this->listeners.push_back(rep);
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