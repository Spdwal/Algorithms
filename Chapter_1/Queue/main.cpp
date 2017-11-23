#include"Queue.h"
#include<iostream>
using namespace std;

int main()
{
	Queue<int>  que;
	for(int i = 0; i < 10; ++i)
	{
		que.push_back(i);
    }
    auto itr = que.begin();
    cout << *itr << endl;
    auto itr2 = que.end();
    cout << *itr2 << endl;
    for(Queue<int>::iterator itr = que.begin(); itr != que.end(); itr++)
    {
        cout << *itr << endl;
    }

    Queue<int> que2 = que;
    for(auto c: que2)
    {
        cout << c <<endl;
    }

    while(!que2.empty())
    {
        cout << que2.pop_front() << endl;
    }
	return 0;
}
