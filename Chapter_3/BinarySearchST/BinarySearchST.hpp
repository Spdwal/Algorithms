#pragma once
#include<vector>
#include<exception>
#include<limits>
#include<iostream>
using namespace std;

template<typename Key, typename Value>
class BinarySearchST{
private:
    int rank(Key key){
        return rank(key, 0, N - 1);
    }
    int rank(Key key, int low, int high){
        if(high < low) return N;
        int mid = low + (high - low) / 2;
        if(key < keys[mid]){
            return rank(key, low, mid - 1);
        }else if(key > keys[mid]){
            return rank(key, mid + 1, high);
        }else return mid;
    }
public:
    BinarySearchST(int capacity = 100):keys{vector<Key>(capacity)}, vals{vector<Value>(capacity)}, N{0} {}
    int size(){
        return N;
    }

    bool isEmpty(){
        return N == 0;
    }
    Value get(Key key){
        if(isEmpty()){
            cout << "The Symbol Table is empty." << endl;
            return numeric_limits<Value>::min();
        }
        int i = rank(key);
        if(i < N && keys[i] == key)
            return vals[i];

        cout << "Can't find the key. " << endl;
        return numeric_limits<Value>::min();
    }

    void put(Key key, Value val){
        int i = rank(key);
        if(i < N && keys[i] == key ){
            vals[i] = val;
            return;
        }
        for(int j = N; j > i; j--){
            keys[j] = keys[j-1];
            vals[j] = vals[j-1];
        }
        keys[i] = key;
        vals[i] = val;
        N++;
    }
private:
    vector<Key> keys;
    vector<Value> vals;
    int N;
};
