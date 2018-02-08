#pragma once
#include"Graph.hpp"
#include<vector>
#include<queue>
#include<iostream>
#include<stack>
using namespace std;

class BFS{
private:
    void bfs(Graph &G, int s){
        queue<int> que;
        markes[s] = true;
        que.push(s);
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(int w : G.adj(v)){
                if(!markes[w]){
                    edgeTo[w] = v;
                    markes[w] = true;
                    que.push(w);
                }
            }
        }
    }
public:
    BFS(Graph &G, int s):S{s}, markes{vector<bool>(G.my_V())}, edgeTo{vector<int>(G.my_V())}{
        bfs(G, s);
    }

    bool hasPathTo(int v){
        return markes[v];
    }

    stack<int> pathTo(int v){
        if(!hasPathTo(v)){
            return stack<int>();
        }

        stack<int> path;
        for(int x = v; x != S; x = edgeTo[x]){
            path.push(x);
        }
        path.push(S);
        return path;
    }
private:
    vector<bool> markes;
    vector<int> edgeTo;
    int S;
};
