#pragma once
#include<vector>
#include<iostream>
#include<functional>
#include<memory>
using namespace std;

template<typename T>
class MathSet{
private:
    int hash_code(T k) const{
        return (hash<T>{}(k) & 0X7FFFFFFF) % M;
    }

    void resize(int cap){
        MathSet<T> tmp(cap);
        for(int i = 0; i < ivec.size(); ++i){
            if(ivec[i] != nullptr){
                tmp.insert(*ivec[i]);
            }
        }
        M = cap;
        ivec = std::move(tmp.ivec);
    }
public:
    MathSet(int m = 16):N{0}, M{m}, ivec{vector<shared_ptr<T>>(M)} {}

    void insert(T k){
        int i = hash_code(k);
        for(; ivec[i] != nullptr; i = (i+1) %M){
            if((*ivec[i]) == k){
                return;
            }
        }
        ivec[i] = make_shared<T>(k);
        N++;
        if(N > (M/2)){
            resize(2*M);
        }
    }

    bool contains(T k) const{
        for(int i = hash_code(k); ivec[i] != nullptr; i = (i+1)%M){
            if(*ivec[i] == k){
                return true;
            }
        }
        return false;
    }
    void print(){
        for(int i = 0; i < M; ++i){
            if(ivec[i] != nullptr){
                cout << *ivec[i] << endl;
            }
        }
    }
    const T operator[](T k){
        int i = hash_code(k);
        while(ivec[i] != nullptr){
            if((*ivec[i]) == k){
                return k;
            }
        }
        cout << "Cant find the key: " << k << endl;
        exit(0);
    }
    void erase(T k){
        if(!contains(k)){
            return ;
        }

        int i = hash_code(k);
        while((*ivec[i]) != k){
            i = (i+1) % M;
        }

        ivec[i] = nullptr;
        i = (i+1)%M;
        while(ivec[i] != nullptr){
            T kTemp = *ivec[i];
            ivec[i] = nullptr;
            N--;
            insert(kTemp);
            i = (i+1)%M;
        }
        N--;
        if(N > 0 && N <= M/8){
            resize(M/2);
        }
    }

    bool isEmpty(){
        return N == 0;
    }

    int size(){
        return N;
    }

    void intersection(const MathSet<T> &rhs){
        vector<T> tmp;

        for(int i = 0; i < M; ++i){
            if(ivec[i] != nullptr){
                if(!rhs.contains(*ivec[i])){
                    tmp.push_back(*ivec[i]);
                }
            }
        }

        for(auto c : tmp){
            erase(c);
        }
    }
    void math_union(const MathSet<T> &rhs){
        for(int i = 0; i < rhs.M; ++i){
            if(rhs.ivec[i] != nullptr){
                insert(*(rhs.ivec[i]));
            }
        }
    }


private:
    int N;
    int M;
    vector<shared_ptr<T>> ivec;
};
