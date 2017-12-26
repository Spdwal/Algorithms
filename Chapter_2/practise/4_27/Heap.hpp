#pragma once
#include<vector>
#include<limits>

using namespace std;


class MaxPQ{
private:
    void swim(int k){
        int tmp = pq[k];
        while(k > 1 && pq[k/2] < tmp){
            pq[k] = pq[k/2];
            k /=2;
        }
        pq[k] = tmp;
    }

    void sink(int k){
        int tmp = pq[k];
        int j = 0;
        while(2*k <= N){
            j = 2 * k;
            if(j < N && pq[j] < pq[j+1])
                j++;
            
            if(tmp > pq[j]){
                break;
            }
            pq[k] = pq[j];
            k = j;
        }
        pq[k] = tmp;
    }

    
public:
    MaxPQ(int maxN = 100):N{0}, pq{vector<int>(maxN)}, Min{numeric_limits<int>::max()} {}
    bool isEmpty() {return N == 0;}
    int size() {return N;}
    void insert(int v){
        if(v <= Min){
            Min = v;
        }
        pq[++N] = v;
        swim(N);
    }

    int delMax(){
        int Max = pq[1];
        std::swap(pq[1], pq[N--]);
        pq[N+1] = 0;
        sink(1);
        return Max;
    }

    int min(){
        return Min;
    }
private:
    vector<int> pq;
    int N;
    int Min;
};
