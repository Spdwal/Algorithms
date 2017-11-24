#include<queue>
#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> lst;
    queue<int> que;
    for(int i = 0; i < 7; ++i)
    {
        lst.push_back(i);
    }

    auto itr = lst.begin();

    while(!lst.empty())
    {
        for(int i = 1; i < 2; ++i)
        {
            itr++;
            if(itr == lst.end())
            {
                itr = lst.begin();
            }
        }
        que.push(*itr);
        itr = lst.erase(itr);
    }

    while(!que.empty())
    {
        cout << que.front() << endl;
        que.pop();
    }

    return 0;
}
