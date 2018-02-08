#pragma once
#include"Graph.hpp"
#include<stack>
using namespace std;

class DepthFirstPaths{
private:
    void dfs(Graph &G, int v){
        markes[v] = true;
        for(auto w : G.adj(v)){
            if(!markes[w]){
                edgeTo[w] = v;
                dfs(G, w);
            }
        }
    }
public:
    DepthFirstPaths(Graph &G, int s):markes{vector<bool>(G.my_V())}, edgeTo{vector<int>(G.my_V())}, S{s}{
        dfs(G, s);
    }

    bool hasPathTo(int v){
        return markes[v];
    }

    vector<int> pathTo(int v){
        if(!hasPathTo(v)){
            cout << "Has No path from " << S << " to " << v <<"." << endl;
            return vector<int>();
        }
        vector<int> path;
        for(int x =v; x != S; x = edgeTo[x]){
            path.push_back(x);
        }
        path.push_back(S);
        return path;
    }
private:
    vector<bool> markes;
    vector<int> edgeTo;
    int S;
};
