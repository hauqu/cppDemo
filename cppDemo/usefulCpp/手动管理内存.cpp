#include<iostream>
using namespace std;
int main()
{
	int* p = new int;
	*p = 1;

	double* pp = new double(12.0);
	cout << p << " :" << *p << endl;
	cout << pp << " :" << *pp << endl;
	delete p;
	delete pp;
	
	int* ps = new  int[4];
	int* temp = ps;
	for (int i = 0; i < 4; i++)
	{
		*temp = i;
		temp++;
	}
	temp = ps;
	for (int i = 0; i < 4; i++)
	{
		cout << temp << " :" << *temp<<endl;
		temp++;
	}
	delete[] ps;
	cin.get();
	return 0;
}
/*
*
*/