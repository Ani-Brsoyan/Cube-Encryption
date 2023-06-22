#pragma once
#include <string>
#include <stack>

class cube
{
	public:
		cube();
		cube(const std::string& str);
		void operator=(const cube& c);
		void R_rot();
		void L_rot();
		void U_rot();
		void D_rot();
		void addDir(char dir);
		char getDir();
		void addCount(int c);
		int getCount();
		bool emptyDir();
		bool emptyCount();
		void print();
		~cube();
	private:
		char* arr;
		int cap;
		std::stack<char> direction;
		std::stack<int> count;
};
