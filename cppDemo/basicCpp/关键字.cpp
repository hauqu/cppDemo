/*
key world of cpp

alignas cpp11,�����ṹ��Ķ��뷽ʽ

alignof cpp11 �����ض�����ֽڷ�ʽ

and �ȼ��� && ������

and_eq �ȼ��� &=  A and_eq B �ȼ���  a = a & b;

asm ���û��

auto �Զ��ж�����


*/
/*
bitand &��λ����
bitor | //��λ���

bool �߼����ͣ����/�Դ� false true sizeof 1���ֽ�

break  �˳�����ѭ������switch ��ʹ��

*/
/*
case ��switchһ��ʹ�ú�

catch ��try һ��ʹ�ã����ڲ����쳣

char �ַ����� ��ռһ���ֽڣ�����ͬ��ƽ̨�����в�ͬ��ʵ��
��linux �� �ȼ���unsigned char ��window�����ַ���

char_16t Unicode  utf8 
char_32t Unicode

class ��

compl  �ȼ���  ~

concept  ����TS ����ģ���̣�

const ������������ ���� ����multithread���߳����кܴ�����

constexpr (cpp11�� 

const_cast �ı�const �Ĳ�����,������ʹ��

continue �����������䣬������һ��ѭ��

*/
/*
decltype 

default

delete �ͷ��ڴ�

do 

double ˫�������� 8�ֽ�

dynamic_cast //�Ѹ���ָ��ת��Ϊ����ָ�룬����ʹ�ã��е�Σ��


*/

/*
else  ``` if

enum ö�����ͣ�����ֻ�� enum class

explicit ������ȷ����ĳ�£���������ʽת�� ���粻������ʽ���죬������ʽ�ĵ��ù��캯��

export ������������

extern 

false 

float �����ȸ�����

for ����ѭ��

friend ��Ԫ����

goto ��ת��ָ��λ��ִ��


*/
struct alignas(8) S
{

};//�ֽڶ��뷽ʽ������Ϊ���ٰ˸��ֽ�//��ѡ0��1��2��4��8��16��......2^n
/*
�ṹ���� ����Ĭ�ϵĶ��뷽ʽ��Ĭ���������ֽڳ�Ա��Ϊ���뷽ʽ

*/
struct Obj
{
	char a;//һ�ֽڶ���
	int b;//���ֽڶ���
};//�ṹ��������ֽڶ��롣����a��ԱҲ��ռ�����ֽڣ�ֻ��һ�ֽڣ�
//��a����*����*����*����b1����b2����b3����b4��
// ���ַ�ʽ���ڼ�������ڴ���Ѱַ
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
	//��a��b ��λ���룬��ֵ��a
	
}

void show_asm()
{
	asm("������");
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
		//c++ ϰ������д
	}
	if(a==true)
	{
		//������Ҫ����д�����ܵ���һЩδ������Ϊ
		//������ʹ��boolֵ��Ϊ��������
	}
}
constexpr int factorial(int n)
{
	return n <= 1 ? 1 : (n * factorial(n - 1));
}

void show_constexpr()
{
	auto a = factorial(4);
	//constexpr ���κ���������������ڱ�������ȷ������ֵ����ֱ�ӽ��м����չ��
	// 	   �������������ڽ�������
	//�ȼ��� auto a = 24;

}

void show_const_cast()
{
	const int a = 3;//��ŵa�Ĳ�����
	int* pa = const_cast<int*>(&a);//���Ʋ�����
	*pa = 4;//�ܹ��ı�a��ֵ��

	//Υ����ŵ��������ʹ�ã����ܵ���δ������Ϊ
}
template<typename T, typename U>
auto add(T a, U b)->decltype(a + b)//�����Ƶ����� 
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
	//�Զ��ƶ�����
	decltype((a->x)) z = y;//double& �����������ŷ��ص������õȼ���auto&
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
	};//ԭʼenum ����Сȡ����ʵ�֣�����û�����ƣ�������������ռ������
	enum class Newcolor :char
	{
		red,green,yello
	};//�Ƽ�ʹ��,�������Ʒ�Χ����һ��ǿ���ͣ���Ҫָ��ǰ׺,���Կ����ظ�

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

	A a1 = 1;//����
	B B1 = 1;//������

	A a2(1);//����
	B b2(1);//����

	A a3 = { 1,2 };//�ȼ��� A a3 = A(4,5);
	B B3 = { 1,2 };//������

	int na1 = a1;//ok

	int na2 = static_cast<int>(a1);
	int nb2 = static_cast<int>(b2);

	int nb1 = b2;//����

	B b4 = (B)4;//����
}

int main(int argc,char**argv)
{
	return 0;
}
