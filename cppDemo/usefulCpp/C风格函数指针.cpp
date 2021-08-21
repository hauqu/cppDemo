#include<iostream>
#include<vector>
using namespace std;

void hello(string s)
{
	cout << s << " hello ..." << endl;
}
void PrintValue(int value)
{
	cout << "value: " << value<<endl;
}

void ForEach(const vector<int>& values, void(*func)(int))
{
	for (int value : values)
		func(value);
}

int main()
{
	typedef void(*helloFunction)(string);
	helloFunction function = hello;
	function("bob");


	vector<int>values = { 1,1,4,5,1,4 };
	ForEach(values, PrintValue);
	ForEach(values, [](int value) {cout << "value: " << value << endl; });
	cin.get();
	return 0;

}