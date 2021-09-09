/*
key world of cpp

alignas cpp11,描述结构体的对齐方式

alignof cpp11 ，返回对齐的字节方式

and 等价于 && 且运算

and_eq 等价于 &=  A and_eq B 等价于  a = a & b;

asm 调用汇编

auto 自动判断类型


*/
/*
bitand &按位求与
bitor | //按位求或

bool 逻辑类型，真假/对错 false true sizeof 1个字节

break  退出本层循环，在switch 中使用

*/
/*
case 与switch一起使用后

catch 与try 一起使用，用于捕获异常

char 字符类型 ，占一个字节，但不同的平台可能有不同的实现
在linux 下 等价于unsigned char ，window下区分符号

char_16t Unicode  utf8 
char_32t Unicode

class 类

compl  等价于  ~

concept  概念TS 用于模板编程，

const 常量，不变性 声明 ，在multithread多线程中有很大作用

constexpr (cpp11起） 

const_cast 改变const 的不变性,不建议使用

continue 跳过下面的语句，继续下一个循环

*/
/*
decltype 

default

delete 释放内存

do 

double 双精度整数 8字节

dynamic_cast //把父类指针转换为子类指针，避免使用，有点危险


*/

/*
else  ``` if

enum 枚举类型，建议只用 enum class

explicit 必须明确的做某事，不允许隐式转换 例如不允许隐式构造，必须显式的调用构造函数

export 基本废弃不用

extern 

false 

float 单精度浮点数

for 用于循环

friend 友元声明

goto 跳转到指定位置执行


*/
struct alignas(8) S
{

};//字节对齐方式，设置为至少八个字节//可选0，1，2，4，8，16，......2^n
/*
结构体中 会有默认的对齐方式，默认以最大的字节成员作为对齐方式

*/
struct Obj
{
	char a;//一字节对齐
	int b;//四字节对齐
};//结构体采用四字节对齐。所以a成员也会占用四字节，只用一字节，
//【a】【*】【*】【*】【b1】【b2】【b3】【b4】
// 这种方式便于计算机在内存中寻址
//sizeof(Obj)== 8;
//aligonf(Obj)== 4;

void show_and()
{
	int a = 1; int b = 2;
	if((a==1)&&(b==2))
	{
		//do something
	}
	a and_eq b;
	//将a和b 按位相与，赋值给a
	
}

void show_asm()
{
	asm("汇编语句");
}

void show_auto()
{
	auto a = 1 + 2;
	
}

void show_bitandor()
{
	auto a = 3L;
	auto b = 1;
	auto c = a bitand b;
}
void show_bool()
{
	bool a = false;
	auto b = true;
	if(a)
	{
		//c++ 习惯这样写
	}
	if(a==true)
	{
		//尽量不要这样写，可能导致一些未定义行为
		//尽量不使用bool值作为函数参数
	}
}
constexpr int factorial(int n)
{
	return n <= 1 ? 1 : (n * factorial(n - 1));
}

void show_constexpr()
{
	auto a = factorial(4);
	//constexpr 修饰函数，如果函数能在编译器就确定返回值，则直接进行计算和展开
	// 	   而不是在运行期进行运算
	//等价于 auto a = 24;

}

void show_const_cast()
{
	const int a = 3;//承诺a的不变性
	int* pa = const_cast<int*>(&a);//打破不变性
	*pa = 4;//能够改变a的值了

	//违反承诺，不建议使用，可能导致未定义行为
}
template<typename T, typename U>
auto add(T a, U b)->decltype(a + b)//后置推导类型 
{
	return a + b;

}
void show_delctype()
{
	struct A
	{
		double x;
	};
	const A* a = new A{ 0 };
	auto aa = a->x;
	decltype(a->x) y;//double y
	//自动推断类型
	decltype((a->x)) z = y;//double& ，参数带括号返回的是引用等价于auto&
	auto& yy = y;
}



struct Base
{
	virtual ~Base(){}
};

struct Derived :Base
{
	virtual void name() {}
};



void show_enum()
{
	enum color
	{
		red,green,yellow
	};//原始enum ，大小取决于实现，由于没有限制，可能造成命名空间的问题
	enum class Newcolor :char
	{
		red,green,yello
	};//推荐使用,可以限制范围，是一种强类型，需要指明前缀,所以可以重复

	Newcolor AA = Newcolor::green;
	color A = color::green;
	switch (A)
	{
	case red:
		break;
	case green:
		break;
	case yellow:
		break;
	default:
		break;
	}
}

void show_explicit()
{
	struct A
	{
		A(int) {}
		A(int ,int ){}
		operator int() const { return 0; }
	};

	struct B
	{
		explicit B(int){}
		explicit B(int,int){}
		explicit operator int()const { return 0; }
	};

	A a1 = 1;//可以
	B B1 = 1;//不可以

	A a2(1);//可以
	B b2(1);//可以

	A a3 = { 1,2 };//等价于 A a3 = A(4,5);
	B B3 = { 1,2 };//不可以

	int na1 = a1;//ok

	int na2 = static_cast<int>(a1);
	int nb2 = static_cast<int>(b2);

	int nb1 = b2;//不行

	B b4 = (B)4;//可以
}

int main(int argc,char**argv)
{
	return 0;
}
