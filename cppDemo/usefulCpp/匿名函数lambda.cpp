#include<iostream>
#include<vector>
using namespace std;
void PrintValue(int value)
{
	cout << "value: " << value << endl;
}

void ForEach(const vector<int>& values, void(*func)(int))
{
	for (int value : values)
		func(value);
}
int main()
{
	vector<int>values = { 1,1,4,5,1,4 };
	auto lambda = [](int value) {cout << "value: " << value << endl; };
	
	ForEach(values, lambda);
	cin.get();
	return 0;
}
/*
https://en.cppreference.com/w/cpp/language/lambda
*/