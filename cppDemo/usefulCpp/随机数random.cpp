#include<iostream>
#include<random>


int main()
{
	std::random_device rd;//��ȡ���������
	std::mt19937 gen(rd());// �������������
	std::uniform_int_distribution<>dis(1, 6);//����������ͺͷ�Χ
	for(int n=0;n<10;n++)
	{
		//std::cout << dis(gen) << std::endl;
	}
	

	return 0;
}
/*
https://en.cppreference.com/w/cpp/numeric/random
*/