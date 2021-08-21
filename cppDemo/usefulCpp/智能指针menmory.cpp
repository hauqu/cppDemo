#include<iostream>
#include<memory>
using std::unique_ptr;//无法复制
using std::shared_ptr;//大多使用引用计数，当计数归0，删除内存,
					  //当将一个shareptr赋值给另一个shareptr引用计数加一
					  //产生额外的内存开销用于控制
using std::weak_ptr;//将一个shareptr赋值给一个weakptr 并不会增加引用计数
using std::cout;
using std::endl;
using std::cin;
class Entity
{
public:
	Entity()
	{
		cout << "Entity Created!" << endl;
	}
	~Entity()
	{
		cout << "Entity Destroyed!" << endl;
	}
	void Print()
	{
		cout << "Entity Working!" << endl;
	}
};

int main()
{
	{
		unique_ptr<Entity> entity(new Entity());
		entity->Print();
		//unique_ptr<Entity>e0 = entity;
		// you can not do this 
	}
	{
		shared_ptr<Entity> shareEntity = std::make_shared<Entity>();
		{
			shared_ptr<Entity> shareEntity1 = shareEntity;
			weak_ptr<Entity> weakEntity = shareEntity;
		}
		
	}
	
	

	cin.get();
	return 0;
}
/*
* https://en.cppreference.com/w/cpp/header/memory
*/