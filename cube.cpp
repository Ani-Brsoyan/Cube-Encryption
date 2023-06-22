#include "cube.h" 
#include <iostream>

cube::cube()
	:arr(nullptr)
	,cap(0)
{}
cube::cube(const std::string& str)
{	
	const int standart = 8;
	cap = str.size();
	arr = new char[standart + 1];
	int i = 0;
	while(str[i] != '\0'){
		arr[i] = str[i];
		++i;	
	}
	for(; i < standart; i++){
		arr[i] = '\t';
	}
}
void cube::operator=(const cube& c){
	const int standart = 8;
	cap = c.cap;
	arr = new char[standart + 1];
	int i = 0;
	for(; i < cap; i++){
		arr[i] = c.arr[i];
	}
	for(; i < standart; i++){
		arr[i] = '\t';
	}
}
void cube::R_rot()
{
	char tmp = arr[1];
	arr[1] = arr[0];
	arr[0] = arr[3];
	arr[3] = arr[2];
	arr[2] = tmp;

	tmp = arr[5];
	arr[5] = arr[4];
	arr[4] = arr[7];
	arr[7] = arr[6];
	arr[6] = tmp;
}
void cube::L_rot()
{
	char tmp = arr[1];
	arr[1] = arr[2];
	arr[2] = arr[3];
	arr[3] = arr[0];
	arr[0] = tmp;

	tmp = arr[5];
	arr[5] = arr[6];
	arr[6] = arr[7];
	arr[7] = arr[4];
	arr[4] = tmp;
}
void cube::U_rot()
{
	char tmp = arr[0];
	arr[0] = arr[3];
	arr[3] = arr[7];
	arr[7] = arr[4];
	arr[4] = tmp;

	tmp = arr[1];
	arr[1] = arr[2];
	arr[2] = arr[6];
	arr[6] = arr[5];
	arr[5] = tmp;
}
void cube::D_rot()
{
	char tmp = arr[0];
	arr[0] = arr[4];
	arr[4] = arr[7];
	arr[7] = arr[3];
	arr[3] = tmp;

	tmp = arr[1];
	arr[1] = arr[5];
	arr[5] = arr[6];
	arr[6] = arr[2];
	arr[2] = tmp;
}
void cube::addDir(char dir)
{
	direction.push(dir);	
}
char cube::getDir()
{
	char ret = direction.top();
	direction.pop();
	return ret;
}
void cube::addCount(int c)
{
	count.push(c);
}
int cube::getCount()
{
	int ret = count.top();
	count.pop();
	return ret;
}
bool cube::emptyDir()
{
	return direction.empty();
}
bool cube::emptyCount()
{
	return count.empty();
}
void cube::print()
{
	for(int i = 0; i < 8; i++){
		std::cout << arr[i]; 
	}
}
cube::~cube()
{
	delete[] arr;
	//std::cout << "destructor\t";
}
