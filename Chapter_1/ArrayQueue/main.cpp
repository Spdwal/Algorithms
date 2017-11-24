#include"ArrayQueue.hpp"
#include<iostream>
using namespace std;

int main()
{
	Queue<int> que;
	for(int i = 0; i < 10; ++i)
	{
		que.push_back(i);
	}
    Queue<int> que2(que);
	while(!que2.empty())
	{
		cout << que2.front() << endl;
		que2.pop_front();
	}

	return 0;
}
