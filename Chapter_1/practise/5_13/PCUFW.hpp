#pragma once
#include<vector>
using namespace std;

class UF{
public:
    UF() = default;
    UF(int n): Count(n), Sz{vector<int>(n)}, Id{vector<int>(n)}{
        for(int i = 0; i < n; ++i){
            Id[i] = i;
            Sz[i] = i;
        }
    }
    int find(int p){
        int root = p;
        while(root != Id[root]){
            root = Id[root];
        }
        //路径压缩
        while(Id[p] != root){
            int temp = p;
            p = Id[p];
            Id[temp] = root;
        }
        return root;
    }

    bool connected(int p, int q){
        return find(p) == find(q);
    }

    void Union(int p, int q){
        int pRoot = find(p);
        int qRoot = find(q);

        if(connected(p, q)){
            return ;
        }
        if(Sz[pRoot] < Sz[qRoot]){
            Sz[qRoot] += Sz[pRoot];
            Id[pRoot] = qRoot;
        }else{
            Sz[pRoot] += Sz[qRoot];
            Id[qRoot] = pRoot;
        }
        Count--;
    }

    int count(){
        return Count;
    }
private:
    vector<int> Sz;
    vector<int> Id;
    int Count;
};
