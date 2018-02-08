#include"DFP.hpp"
#include<iostream>
using namespace std;


int main()
{
    Graph G(7);
    cin >> G;
    cout << G.toString() << endl;

    DepthFirstPaths DFP(G, 0);

    vector<int> ivec = DFP.pathTo(5);
    for(auto c : ivec){
        cout << c << endl;
    }
    return 0;
}
