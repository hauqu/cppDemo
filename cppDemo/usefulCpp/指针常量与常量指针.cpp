#include<iostream>
using std::cout;
using std::endl;
int main()
{
	
	const int c1 = 1;
	const int* p = &c1;//常量指针，一个指向常量的指针，是一个变量，可以修改
	const int c2 = 2;
	p = &c2;
	/*
	*p = 1; 非法，因为指向的值是一个常量无法被修改
	*/
	int v1 = 3;
	int* const cp = &v1;//指针常量 ，本身是一个常量，指向一个变量，变量的值可以修改
	int v2 = 4;
	*cp = v2;//可以修改指针所指的值，但是不能修改地址
	
	/*
		cp = &v2; 非法，因为常量不可修改
	*/


	const int v3 = 5;
	const int v4 = 6;
	const int* const pp = &v3;//常量指针常量,常量指针，指向一个常量
	return 0;
}