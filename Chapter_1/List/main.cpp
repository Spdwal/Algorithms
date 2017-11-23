#include"List.hpp"
#include<iostream>
using namespace std;

int main()
{
	List<int> l;
	for(int i = 0; i < 10; ++i)
	{
		l.push_back(i);
		cout << i  << endl;
	}

	for(auto c: l)
	{
		cout << c << endl;
	}

	return 0;
}
