#pragma once
#include<vector>
#include<iostream>

using namespace std;

class UF{
public:
    UF() = default;
    UF(int n): Count{n}, Id{vector<int>(n)}, High{vector<int>(n)}{
        for(int i = 0; i < n; ++i){
            Id[i] = i;
            High[i] = 1;
        }
    }
    int find(int p){
        if(p > Id.size()){
            resize(p);
        }
        while(p != Id[p]){
            p = Id[p];
        }
        return p;
    }

    bool connected(int p, int q){
        return find(p) == find(q);
    }

    int count(){
        return Count;
    }

    void resize(int n){
        vector<int> tmpId(n);
        vector<int> tmpHeight(n);
        for(int i = 0; i < tmpId.size(); ++i){
            if(i < Id.size()){
                tmpId[i] = Id[i];
                tmpHeight[i] = High[i];
            }else{
                tmpId[i] = i;
                tmpHeight[i] = 1;
            }
        }
        Count += (n - Id.size());
        Id = tmpId;
        High = tmpHeight;
    }

    void Union(int p, int q){
        
        int pRoot = find(p);
        int qRoot = find(q);
        cout << "pRoot: " << pRoot << endl;
        cout << "qROot: " << qRoot << endl;
        if(High[pRoot] == High[qRoot]){
            High[pRoot] += 1;
            Id[qRoot] = pRoot;
        }else if(High[pRoot] > High[qRoot]){
            Id[qRoot] = pRoot;
        }else{
            Id[pRoot] = qRoot;
        }
        for(int i = 0; i < Id.size(); ++i){
            cout << Id[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < Id.size(); ++i){
            cout << High[i] << " ";
        }
        cout << endl;
        Count--;
        cout <<"Count: "<< Count << endl;
    }
private:
    int Count;
    vector<int> Id;
    vector<int> High;
};
