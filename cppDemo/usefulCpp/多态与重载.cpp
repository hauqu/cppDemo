#include<iostream>
using namespace std;
/*
��̬��
	���ض�̬
	ǿ�ƶ�̬
	������̬

��̬��
	������̬
*/
void Fun()
{
	cout << "fun working!" << endl;
}
void Fun(string s)
{
	cout<<s << " fun working!" << endl;
}

class Complex
{
public:

	Complex(double r=0.0,double i =0.0):
		real(r),imag(i)
	{

	}
	void display() const
	{
		cout << "(" << real << "," << imag << ")" << endl;
	}
	Complex operator+(const Complex& B)//��������أ��������Ǻ�������/
	{
		return Complex(this->real+B.real,this->imag+B.imag);
	}
	Complex operator-(const Complex& B)//��������أ��������Ǻ�������/
	{
		return Complex(this->real - B.real, this->imag - B.imag);
	}
	Complex& operator++()//û�в��� ��ǰ�õ�Ŀ�����
	{
		Complex c= Complex(this->real + 1.0, this->imag + 1.0);
		return c;
	}
	Complex operator++(int)//int���� �������õ�Ŀ�����
	{
		Complex c = Complex(this->real + 1.0, this->imag + 1.0);
		return c;
	}


	~Complex() {};
private:
	double real;
	double imag;
};
int main()
{
	Fun();//�������أ�����ʱ����
	Fun("hello");//�������أ���ͬ�ĺ������Ʋ�ͬ�Ĳ���������ͬ�ĺ���
	Complex A(1.0, 1.0);
	Complex B(8.0, 7.0);
	A = A + B;
	A.display();
	cin.get();
	return 0;
}
/*

�������������5��

.
.*
::
?:
sizeof()

*/