#include<iostream>
using std::cout;
using std::endl;

int main()
{
	int a = 0;
	int b = 1;

	if (a>b)
	{
		cout << "a>b" << endl;
	}
	else if(a<b)
	{
		cout << "a<b" << endl;
	}
	else {
		cout << "a=b" << endl;
	}
	int day = 5;
	switch (day)
	{
	case 0:
		cout << "������" << endl;
		break;
	case 1:
		cout << "����1" << endl;
		break;
	case 2:
		cout << "����2" << endl;
		break;
	case 3:
		cout << "����3" << endl;
		break;
	case 4:
		cout << "����4" << endl;
		break;
	case 5:
		cout << "����5" << endl;
		break;
	case 6:
		cout << "����6" << endl;
		break;
	default:
		cout << "������Χ" << endl;
		break;
	}
	system("pause");
	return 0;

}