#pragma once
#include<vector>
using namespace std;

class UF{
public:
    UF(int n):Sz(vector<int>(n)),Id(vector<int>(n)), Count(n){
        for(int i = 0; i < n; ++i)
        {
            Id[i] = i;
            Sz[i] = i;
        }
    }
    int count(){
        return Count;
    }
    bool connected(int p, int q){
        return find(p) == find(q);
    }
    int find(int p){
        while(p != Id[p]){
            p = Id[p];
        }
        return p;
    }

    void Union(int p, int q){
        int i = find(p);
        int j = find(q);

        if(Sz[i] < Sz[j]){
            Id[i] = j;
            Sz[j] += Sz[i];
        }else{
            Id[j] = i;
            Sz[i] += Sz[j];
        }
        Count--;
    }
private:
    vector<int> Sz;
    vector<int> Id;
    int Count;
};
