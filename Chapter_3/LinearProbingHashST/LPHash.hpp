#pragma once
#include<vector>
#include<functional>
#include<iostream>
#include<memory>
using namespace std;

template<typename Key, typename Value>
class LPHash{
private:
    unsigned int hash_code(Key k){
        return (std::hash<Key>{}(k) & 0x7FFFFFFF) % M;
    }

    void resize(int cap){
        LPHash<Key, Value> temp(cap);
        for(int i = 0; i < M; ++i){
            if(keys[i] != nullptr){
                temp.insert(*keys[i], vals[i]);
            }
        }
        keys = std::move(temp.keys);
        vals = std::move(temp.vals);
        M = std::move(temp.M);
    }

    bool contains(Key k){
        for(int i = hash_code(k); keys[i] != nullptr; i = (i+1)%M){
            if(*keys[i] == k){
                return true;
            }
        }
        return false;
    }

public:
    LPHash(int m = 16): M{m}, keys{vector<shared_ptr<Key>>(m)}, vals{vector<Value>(m)},N{0}{}
    void insert(Key k, Value v){
        if(N >= M/2){
            resize(2*M);
        }

        int i;
        for(i = hash_code(k); keys[i] != nullptr; i = (i+1) % M){
            if(*keys[i] == k){
                vals[i] = v;
                return ;
            }
        }
        keys[i] = make_shared<Key>(k);
        vals[i] = v;
        N++;
    }

    Value get(Key k){
        for(int i = hash_code(k); keys[i] != nullptr; i = (i+1) %M){
            if(*keys[i] == k){
                return vals[i];
            }
        }
        cout << "Can't find " << k << endl;
        exit(1);
    }

    void erase(Key k){
        if(!contains(k)){
            return ;
        }
        int i = hash_code(k);
        while(!(*keys[i] == k)){
            i = (i + 1) % M;
        }
        keys[i] = nullptr;
        while(keys[i] != nullptr){
            shared_ptr<Key> ktemp = keys[i];
            Value vtemp = vals[i];
            keys[i] = nullptr;
            N--;
            insert(*ktemp, vtemp);
            i = (i+1) %M;
        }
        N--;
        if(N>0 && N == M/8)
            resize(M/2);
    }
private:
    int N;
    int M;
    vector<shared_ptr<Key>> keys;
    vector<Value> vals;
};
