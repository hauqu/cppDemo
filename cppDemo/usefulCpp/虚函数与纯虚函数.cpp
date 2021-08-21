#include<iostream>
#include<memory>
using std::unique_ptr;//�޷�����
using std::shared_ptr;//���ʹ�����ü�������������0��ɾ���ڴ�,
					  //����һ��shareptr��ֵ����һ��shareptr���ü�����һ
					  //����������ڴ濪�����ڿ���
using std::weak_ptr;//��һ��shareptr��ֵ��һ��weakptr �������������ü���
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