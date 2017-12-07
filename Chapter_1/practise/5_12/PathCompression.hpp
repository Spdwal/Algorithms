#pragma once
#include<vector>
using namespace std;

class UF{
public:
    UF() = default;
    UF(int n):Id{vector<int>(n)}, Count{n} {
        for(int i = 0; i < n; ++i)
        {
            Id[i] = i;
        }
    }
    int find(int p){
        int root = p;
        while(root != Id[root]){
            root = Id[root];
        }
        //一直佚代到根节点为止。
        while(Id[p] != root){
            //保存自身节点。
            int temp = p;
            //往父节点走。
            p = Id[p];
            //将父节点的值设为root
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
        if(connected(p, q))
            return;
        else{
            Id[pRoot] = qRoot;
            Count--;
        }
    }

    int count(){
        return Count;
    }
private:
    vector<int> Id;
    int Count;
};
