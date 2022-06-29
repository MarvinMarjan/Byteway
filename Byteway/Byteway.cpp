#include <iostream>

#include "repository.hpp"
#include "listener.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	Listener listener;

	vector<Repository> rep = {
		{"test1", "C:/Users/Usuario/Desktop/test"},
		{"test2", "C:/Users/Usuario/Desktop/test2"}
	};

	for (Repository rp : rep)
		listener.add(rp);
	
	while (true)
	{
		for (Repository repo : listener.get_all())
			if (listener.update(repo))
				cout << "Repository: " << repo.get_name() << " has changed" << endl;

		system("cls");
	}
}