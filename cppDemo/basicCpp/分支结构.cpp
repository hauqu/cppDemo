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
		cout << "星期天" << endl;
		break;
	case 1:
		cout << "星期1" << endl;
		break;
	case 2:
		cout << "星期2" << endl;
		break;
	case 3:
		cout << "星期3" << endl;
		break;
	case 4:
		cout << "星期4" << endl;
		break;
	case 5:
		cout << "星期5" << endl;
		break;
	case 6:
		cout << "星期6" << endl;
		break;
	default:
		cout << "超出范围" << endl;
		break;
	}
	system("pause");
	return 0;

}