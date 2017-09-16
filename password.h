#ifndef PASSWORD_H
#define PASSWORD_H

#include <vector>
#include<string>
using namespace std;

class Password
{
public:
	Password();
	string get_password();
	string make_password();
private:
	void populate_generator_arrays();
	string password;
	vector<vector<char>> password_generator_array;
};


#endif // !VECTOR_H
