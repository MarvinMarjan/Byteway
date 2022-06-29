#include <iostream>
#include <string>

#include "repository.hpp"
#include "listener.hpp"
#include "color.hpp"
#include "input.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	system("color");

	Listener listener;
	Input inp;
	
	while (!inp.abort)
	{
		cout << "Byteway" << GREEN " $> " DEF;
		inp.set(inp.get());

		
		for (Repository rep : listener.get_all())
		{
			if (listener.update(rep))
				listener.add_mod(rep);

			else
				if (listener.find_mod(rep) != -1)
					listener.remove_mod(rep);
		}

		if (inp.command == "clear")
			system("cls");

		else if (inp.command == "add")
		{
			Repository rep(inp.args[0], inp.args[1]);
			listener.add(rep);
		}

		else if (inp.command == "rmv")
		{
			if (listener.find(inp.args[0]) != -1)
				listener.remove(listener.get(inp.args[0]));

			else
				cout << "couldn't found repository: " << GREEN << '\"' + inp.args[0] + '\"' << DEF << endl;

			if (listener.find_mod(inp.args[0]) != -1)
				listener.remove_mod(listener.get(inp.args[0]));
		}

		else if (inp.command == "view")
		{
			for (Repository rep : listener.get_all())
			{
				if (listener.find_mod(rep) != -1)
					cout << rep.get_name() << GREEN " *" DEF << endl;

				else
					cout << rep.get_name() << endl;
			}
		}
	}
}