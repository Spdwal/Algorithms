#pragma once
#include"Graph.hpp"
#include<vector>
using namespace std;

class CC{
private:
    void dfs(Graph &G, int v){
        markes[v] = true;
        id[v] = cnt;
        for(int w : G.adj(v)){
            if(!markes[w]){
                dfs(G, w);
            }
        }
    }
public:
    CC(Graph &G):markes{vector<bool>(G.my_V())}, id{vector<int>(G.my_V())}, cnt{0} {
        for(int s = 0; s <G.my_V(); s++){
            if(!markes[s]){
                dfs(G, s);
                cnt++;
            }
        }
    }

    bool connected(int v, int w){
        return id[v] == id[w];
    }

    int Id(int v){
        return id[v];
    }

    int count(){
        return cnt;
    }
private:
    vector<bool> markes;
    vector<int> id;
    int cnt;
};
