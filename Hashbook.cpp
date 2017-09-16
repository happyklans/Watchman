#include <fstream>
#include <string>
#include <iostream>
#include "Hashbook.h"
#include "password.h"
using namespace std;

Hashbook::Hashbook()
{
	fstream hashbook;
	string line;
	string password;
	string compname;
	int line_location = 0;
}

void Hashbook::write_to_hashbook(string password, string company_name)
{	
	hashbook.open("Hashbook.txt", ios::app);
	
	hashbook << company_name << "/" << password << "\n";

	hashbook.close();
}

void Hashbook::search_hashbook(string company_name)
{
	do
	{
		string line;

		getline(hashbook, line);

		if (line.length() == 0)
		{
			return;
		}


		if (line.find(company_name) != -1)
		{
			return;
		}
		else if (line.find(EOF) != -1)
		{
			return;
		}

		line_location++;

	} while (true);
}

string Hashbook::get_line()
{
	string line;

	hashbook.open("Hashbook", ios::in);

}
