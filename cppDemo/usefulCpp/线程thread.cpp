#include<thread>
#include<iostream>

using std::cout;
using std::cin;
using std::endl;
using std::thread;
void Work()
{
	using namespace std::literals::chrono_literals;
	while (true)
	{
		cout << "Working..." << std::this_thread::get_id()<<endl;
		std::this_thread::sleep_for(1s);
	}
}
int main()
{
	thread worker(Work);
	//worker.join();//�ڵ�ǰ�߳��ϵȴ�����߳���ɹ���
	while (true)
	{
		using namespace std::literals::chrono_literals;
		cout << "Working..." << std::this_thread::get_id() << endl;
		std::this_thread::sleep_for(1s);
	}
	

	cin.get();
}
/*
https://en.cppreference.com/w/cpp/thread/thread
*/