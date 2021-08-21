#include<iostream>
using namespace std;
/*
静态绑定
	重载多态
	强制多态
	参数多态

动态绑定
	包含多态
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
	Complex operator+(const Complex& B)//运算符重载，本质上是函数重载/
	{
		return Complex(this->real+B.real,this->imag+B.imag);
	}
	Complex operator-(const Complex& B)//运算符重载，本质上是函数重载/
	{
		return Complex(this->real - B.real, this->imag - B.imag);
	}
	Complex& operator++()//没有参数 ，前置单目运算符
	{
		Complex c= Complex(this->real + 1.0, this->imag + 1.0);
		return c;
	}
	Complex operator++(int)//int参数 ，后置置单目运算符
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
	Fun();//函数重载，编译时决定
	Fun("hello");//函数重载，相同的函数名称不同的参数看作不同的函数
	Complex A(1.0, 1.0);
	Complex B(8.0, 7.0);
	A = A + B;
	A.display();
	cin.get();
	return 0;
}
/*

不可重载运算符5个

.
.*
::
?:
sizeof()

*/