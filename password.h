#pragma once
#include "cube.h"

class password
{
	public:
		password();
		password(const std::string& str);
		void encrypt(const std::string& key);
		void decrypt(const std::string& key);
		void show();
		~password();
	private:
		cube* myCubes;
		int num;
};
