#pragma once
#include"Graph.hpp"
using namespace std;

class DepthFirstSearch{
private:
    bool marked(int w){
        return markes[w];
    }
    
    void dfs(const Graph &G, int v){
        markes[v] = true;
        cnt++;
        for(int w : G.adj(v)){
            if(!markes[w]){
                dfs(G, w);
            }
        }
    }
public:
    DepthFirstSearch(Graph G, int s):markes{vector<int>(G.my_V())}{
        dfs(G, s);
    }

    int count(){
        return cnt;
    }
private:
    vector<bool> markes;
    int cnt;
}

