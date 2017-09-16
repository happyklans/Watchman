#ifndef  HASHBOOK_H
#define HASHBOOK_H
#define FOUND = 1
#define NOT_FOUND = 0;


#include <fstream>					
#include <string>
using namespace std;

class Hashbook
{
public:
	Hashbook();
	void write_to_hashbook(string, string);
	int search_hashbook(string);
	string get_password(string);
private:
	fstream hashbook;
	int line_location;
};


#endif // ! HASHBOOK_H
