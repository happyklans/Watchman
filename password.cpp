#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "password.h"
using namespace std;


Password::Password()
{
	populate_generator_arrays();
	return;
}

string Password::get_password()
{
	return password;
}

void Password::populate_generator_arrays()

{


	vector<char> LatinL; // lowercase letters (26 in total)

	vector<char> LatinU; //capital letters (26 in total)

	vector<char> Arabic; //0-9

	vector<char> Saxon; // "special characters" !@$ etc (arbitarily choose 18 common characters)

	

	int list_populator; //used to poulate lists with the characters



	LatinL.begin();

	LatinU.begin();

	Arabic.begin();

	password_generator_array.begin();



	Saxon = { '!', '@', '#', '$', '%', '%', '^', '&', '*', '?', '_', '=', '+', '<', '>', '-', '(', ')' };

	password_generator_array.push_back(Saxon); //add to return vector



	list_populator = 97; // ASCII value for "a"

	for (int i = 0; i < 26; i++)
	{
		LatinL.push_back(list_populator); //inserts "a" to position 0 on first iteration, "b" to position 1 on second etc.

		list_populator++;

	}

	password_generator_array.push_back(LatinL);



	list_populator = 65; // ASCII value for "A"

	for (int j = 0; j < 26; j++)
	{
		LatinU.push_back(list_populator); //inserts "A" to position 0 on first iteration, "B" to position 1 on second etc.

		list_populator++;

	}

	password_generator_array.push_back(LatinU);


	list_populator = 48;

	for (int k = 0; k < 10; k++)
	{


		Arabic.push_back(list_populator); //populating our number list

		list_populator++;

	}

	password_generator_array.push_back(Arabic); //add to return vector

	return;

}

string Password::make_password()

{
	int required_chars; //guarantees the presense of an upper case letter, a lower case letter, a number, and a special character, satisfying the vast majority of users.

	int req_char_summon; // used to decide if a required char will be inserted at this time.

	int vector_choice;	//decides which of the 4 verctors the requiered char will be taken from, if at all

	int rand_char; //used to summon the elements of the vectors of chars


	required_chars = 4;

	srand((unsigned int)time(NULL));


	for (int i = 0; i < 10; i++)
	{
		req_char_summon = rand() % 2;

		if (req_char_summon == 1 && required_chars != 0)
		{
			vector_choice = rand() % required_chars;

			rand_char = rand() % 10;

			password += password_generator_array[vector_choice][rand_char];

			required_chars--;
		}

		else
		{
			vector_choice = rand() % 4;

			rand_char = rand() % password_generator_array[vector_choice].size();

			password += password_generator_array[vector_choice][rand_char];
		}
	}

	return password;
}