#include"Stack.hpp"
#include<iostream>
using namespace std;
int main()
{
	Stack<int> stack;
	for(int i = 0; i < 10; ++i)
	{
		stack.push(i);
		cout << stack.top() << endl;
	}

	stack.emplace(20);
	while(!stack.empty())
	{
		cout << stack.pop() << endl;
	}

	return 0;
}
