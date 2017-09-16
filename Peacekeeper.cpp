//B.R.S
//void
//3-2-2017

#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <time.h>
#include <cstdio>
#include <password.h>
using namespace std;

void opnwpswd()
{
	fstream Hashbook;

	string compname; //name of pswd org

	Password new_password; // unhashed pswd string

	string recovered_password;

	string line;

	

	Hashbook.open("Hashbook.txt", ios::in);

	

	//Get compname for database
	cout << "\nEnter the name of the organization you require a password for: ";

	getline(cin, compname);

	for (int i = 0; i < compname.length(); i++)
	{
		compname[i] = toupper(compname[i]);
	}

	while (true)
	{
		getline(Hashbook, line);
		
		if (line.length() == 0)
		{	
			break;
		}
		

		if (line.find(compname) != -1)
		{
			recovered_password = line.substr(line.find('/') + 1);

			cout << "You already have an account with that organization."
				"Your password for your " << compname << " account is " << recovered_password << "\n\n";

			return;
		}
		else if (line.find(EOF) != -1)
		{
			break;
		}
	}
	Hashbook.close();

	Hashbook.open("Hashbook.txt", ios::app);
	
	new_password.make_password();

	cout << "\nType this into your password and confirm password fields: " << new_password.get_password() << "\n" << endl;


	//write compname/pswd to txt file
	Hashbook << compname << "/" << new_password.get_password() << "\n";

	Hashbook.close();
	
	
	
	return;
}

void opgetpswd()
{
	string compname;

	string pswd;

	string line;

	fstream Hashbook;

	

	Hashbook.open("Hashbook.txt", ios::in);

	cout << "\nEnter the name of the organization you need your password for: ";

	getline(cin, compname);

	for (int i = 0; i < compname.length(); i++)
	{
		compname[i] = toupper(compname[i]);
	}

	while (true)
	{
		getline(Hashbook, line);
		
		if (line == "")
		{
			
			cout << "No such password exists. You have not created an account with this organization.\n\n";

			break;
		}

		
		
		if (line.find(compname) != -1)
		{
			pswd = line.substr(line.find('/')+1);

			cout << "Your password for your " << compname << " account is " << pswd << "\n\n";

			break;
		}
		else if (line.find(EOF) != -1)
		{
			cout << "No such password exists. You have not created an account with this organization.";

			break;
		}
	}
	
	Hashbook.close();

	return;
}



int main()
{
	string operation; // "main menu" selector

	bool kill_loop_main; //controls the main loop



	kill_loop_main = false;
	


	cout << "---------------------Peacekeeper-------------------------\n"
			"		   the open source password manager				  \n"
			<< endl;
	
	
	
	while (kill_loop_main == false)
	{
		cout << "Please select an action:								  \n"
			"Make New Password										  \n"
			"Get Password											  \n"
			"Exit													  \n"
			">> ";
			
		
		getline(cin, operation);
		
		if (operation == "Make New Password")
		{
			opnwpswd();
		}

		if (operation == "Get Password")
		{
			opgetpswd();
		}

		if (operation == "Exit")
		{
			kill_loop_main = true;
		}
		
	}



	return 0;
}
