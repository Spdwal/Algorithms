#include"BFS.hpp"
#include<iostream>
#include<vector>
using namespace std;


int main()
{
    Graph G(7);
    cin >> G;

    BFS From0(G, 0);

    stack<int> s = From0.pathTo(5);
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}
