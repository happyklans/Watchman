#include <iostream>
#include "password.h"
#include "Hashbook.h"

using namespace std;

int main()
{
	Password secret;
	
	secret.make_password();
	secret.get_password();

	system("pause");

	return 0;

}