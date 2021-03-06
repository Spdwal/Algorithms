#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Graph{
private:

public:
    Graph() = delete;
    Graph(int v):V{v}, E{0}, ivec{vector<vector<int>>(V)} {}

    void addEdge(int v, int w){
        if(count(ivec[v].begin(), ivec[v].end(), w) == 0){
            ivec[v].push_back(w);
            ivec[w].push_back(v);
            E++;
        }
     }
    
    friend istream& operator>>(istream &in, Graph &G);
    int my_V() const{ return V;}
    int my_E() const{ return E;}

    vector<int> adj(int v){
        return ivec[v];
    }

    int degree(int v){
        return ivec[v].size();
    }

    int max_degree(){
        int max = 0;
        for(auto v: ivec){
            if(v.size() > max){
                max = v.size();
            }
        }
        return max;
    }

    double avg_degree(){
        return 2*E/V;
    }

    int number_of_selfloops(){
        int cnt = 0;
        for(int v= 0; v< V; v++){
            for(auto w : ivec[v]){
                if(w == v){
                    cnt++;
                }
            }
        }
        return cnt/2;
    }

    string toString(){
        string s = to_string(V) + " vertives, " + to_string(E) + " edges\n";
        for(int v = 0; v < V; v++){
            s += to_string(v) + ": ";
            for(auto w : ivec[v]){
                s += to_string(w) + " ";
            }
            s += "\n";
        }
        return s;
    }
private:
    int V;
    int E;
    vector<vector<int>> ivec;
};

istream& operator>>(istream& in, Graph &G)
{
    int size = 0;
    in >> size;
    int v;
    int w;
    for(int i  = 0; i < size; i++){
        in >> v >> w;
        G.addEdge(v, w);
    }
}
