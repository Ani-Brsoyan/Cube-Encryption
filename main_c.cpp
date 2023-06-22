#include <iostream>
#include "password.h"

int main()
{
	std::string myStr = "Hello dear students!";
	password p(myStr);
	//p.show();
	std::string key = "L2:L3:U2";
	p.encrypt(key);
	p.show();	
	p.decrypt(key);
	p.show();
	return 0;
}
