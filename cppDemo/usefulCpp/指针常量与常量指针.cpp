#include<iostream>
using std::cout;
using std::endl;
int main()
{
	
	const int c1 = 1;
	const int* p = &c1;//����ָ�룬һ��ָ������ָ�룬��һ�������������޸�
	const int c2 = 2;
	p = &c2;
	/*
	*p = 1; �Ƿ�����Ϊָ���ֵ��һ�������޷����޸�
	*/
	int v1 = 3;
	int* const cp = &v1;//ָ�볣�� ��������һ��������ָ��һ��������������ֵ�����޸�
	int v2 = 4;
	*cp = v2;//�����޸�ָ����ָ��ֵ�����ǲ����޸ĵ�ַ
	
	/*
		cp = &v2; �Ƿ�����Ϊ���������޸�
	*/


	const int v3 = 5;
	const int v4 = 6;
	const int* const pp = &v3;//����ָ�볣��,����ָ�룬ָ��һ������
	return 0;
}