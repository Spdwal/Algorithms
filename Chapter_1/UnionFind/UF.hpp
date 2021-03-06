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
        return Id[p];
    }

    void Union(int p, int q){
        int pID = find(p);
        int qID = find(q);
        if(pID == qID){
            return;
        }
        for(int i = 0; i < Id.size(); ++i){
            if(Id[i] == pID){
                Id[i] = qID;
            }
        }
        Count--;
    }
private:
    vector<int> Id;
    int Count;
};
