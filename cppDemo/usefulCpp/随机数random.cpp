#include<iostream>
#include<random>


int main()
{
	std::random_device rd;//获取随机数种子
	std::mt19937 gen(rd());// 设置随机数引擎
	std::uniform_int_distribution<>dis(1, 6);//限制输出类型和范围
	for(int n=0;n<10;n++)
	{
		//std::cout << dis(gen) << std::endl;
	}
	

	return 0;
}
/*
https://en.cppreference.com/w/cpp/numeric/random
*/