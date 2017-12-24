#pragma once
#include<vector>
#include<limits>
using namespace std;


class BinaryHeap{
public:
    BinaryHeap():ivec{}, Size{0}{ ivec.push_back(numeric_limits<int>::max());}
    bool empty() {return Size == 0;}
    int size() { return Size; }
    void insert(int v){
        Size++;
        ivec.push_back(v);
        swim(ivec.size() - 1);
    }

    int delMax(){
        int Max = ivec[1];
        exchange(1, Size--);
        ivec.pop_back();
        sink(1);
        return Max;
    }
private:
    bool less(int i, int j) { return ivec[i] < ivec[j];}
    void exchange(int i, int j) { std::swap(ivec[i], ivec[j]);}
    void swim(int k){
        while(k > 1 && less(k/2, k)){
            exchange(k/2, k);
            k /= 2;
        }
    }

    void sink(int k){
        while(k * 2 <= Size){
            int j = 2 * k;
            if(j < Size && less(j, j + 1)) j++;
            if(!less(k, j)) break;
            exchange(k, j);
            k = j;
        }
    }
    int Size;
    vector<int> ivec;
};
