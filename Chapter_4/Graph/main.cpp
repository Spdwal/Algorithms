#include"Graph.hpp"
#include"DFS.hpp"
#include<iostream>
using namespace std;


int main()
{
    Graph G(7);
    cin >> G;
    cout << G.toString() << endl;
    return 0;
}
