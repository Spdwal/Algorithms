#pragma once
#include<vector>
using namespace std;

class UF{
public:
    UF(int n):Id(vector<int>(n)), Count(n){
        for(int i = 0; i < n; ++i)
        {
            Id[i] = i;
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
            p = id[p];
        }
        return p;
    }

    void Union(int p, int q){
        int pRoot = find(p);
        int qRoot = find(q);
        if(pRoot == qRoot){
            return;
        }
        Id[pRoot] = qRoot;
        Count--;
    }
private:
    vector<int> Id;
    int Count;
};
