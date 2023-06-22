#include "password.h"
#include <iostream>

password::password()
	:myCubes(nullptr)
	,num(0)
{}
password::password(const std::string& str)
{
	//8 is the number of the top of the cube 
	num = str.size() / 8;
	if(str.size() % 8 != 0){
		num += 1;
	}
	myCubes = new cube[num];
	for(int i = 0; i < num; i++){
		cube tmp(str.substr(i * 8, 8));
		myCubes[i] = tmp;
	}
//	std::cout << "constructor\n";
}
void password::encrypt(const std::string& key)
{
	int i = 0;
	int cubeIndex = 0;
	while(key[i] != '\0' && cubeIndex < num){
		char rot = key[i];
		++i;
		int count = 0;
		while(key[i] != ':' && key[i] != ',' && key[i] != '\0'){
			int tmp = key[i] - '0';
			count *= 10;
			count += tmp;
			i++;	
		}
		switch(rot){
			case 'L':
				while(count){
					myCubes[cubeIndex].L_rot();
					count--;
				}
				break;
			case 'R':
				while(count){
					myCubes[cubeIndex].R_rot();
					count--;
				}
				break;					
			case 'U':
				while(count){
					myCubes[cubeIndex].U_rot();
					count--;
				}
				break;
			case 'D':
				while(count){
					myCubes[cubeIndex].D_rot();
					count--;
				}
				break;
			default:
				std::cout << "Invalid key\n";
				return;		
		}
		if(key[i] == ':'){
			++cubeIndex;
		}
		if(key[i] != '\0'){
			++i;
		}
	}
}
void password::decrypt(const std::string& key)
{
	int i = 0;
	int cubeIndex = 0;
	while(key[i] != '\0' && cubeIndex < num){
		char rot = key[i];
		++i;
		int count = 0;
		while(key[i] != ':' && key[i] != ',' && key[i] != '\0'){
			int tmp = key[i] - '0';
			count *= 10;
			count += tmp;
			i++;	
		}
		myCubes[cubeIndex].addDir(rot);
		myCubes[cubeIndex].addCount(count);
		if(key[i] == ':'){
			++cubeIndex;
		}
		if(key[i] != '\0'){
			++i;
		}
	}
	for(int cube = 0; cube < num; cube++){
		while(!(myCubes[cube].emptyDir()) && !(myCubes[cube].emptyCount())){
			char tmpD = myCubes[cube].getDir();
			int tmpC = myCubes[cube].getCount();
			switch(tmpD){
				case 'L':
					while(tmpC){
						myCubes[cube].R_rot();
						--tmpC;
					}
					break;
				case 'R':
					while(tmpC){
						myCubes[cube].L_rot();
						--tmpC;
					}
					break;
				case 'U':
					while(tmpC){
						myCubes[cube].D_rot();
						--tmpC;
					}
					break;
				case 'D':
					while(tmpC){
						myCubes[cube].U_rot();
						--tmpC;
					}
					break;
				default:
					std::cout << "Invalid key\n";

			}
		}
	}	
}
void password::show(){
	for(int i = 0; i < num; i++){
		myCubes[i].print();
	}
	std::cout << std::endl;
}
password::~password()
{
	delete[] myCubes;
}
