#pragma once
#include<vector>
#include<limits>
#include<iostream>
using namespace std;


class IndexMinPQ{
private:
    void less(int a, int b){
        return keys[pq[a]] < keys[pq[b]];
    }
    void exchange(int a, int b){
        //改变pq这个二叉堆的同时，也维护它的索引。
        std::swap(pq[a], pq[b]);
        qp[pq[i]] = i;
        qp[pq[j]] = j;
    }
    void swim(int k){
        while(k > 1 && less(k/2, k)){
            exchange(k/2, k);
            k /= 2;
        }
    }

    void sink(int k){
        while(2 * k <= N){
            int j = 2 * k;
            if(less(j, j + 1)){
                j++;
            }
            if(less(k, j)){
                break;
            }
            exchange(k, j);
            k = j;
        }
    }
public:
    IndexMinPQ(int maxN = 100): N{0}, pq{vector<int>(maxN + 1)}, qp{vector<int>(maxN + 1)}, keys(vector<int>(maxN+1)){
        for(int n = 0; n <= maxN; ++i){
            qp[i] = -1;
        }
    }

    bool empty() { return N == 0;}

    bool contains(int k){
        return qp[k] != -1;
    }

    int max_index(){
        if(N == 0){
            cout << "Priority queue underflow" << endl;
            return numeric_limits<int>::min();
        }
    }
    void insert(int k, int key){
        if(contains(i)){
            cout << "index is already in the priority queue" << endl;
            exit(0);
        }
        N++;
        qp[k] = N;
        pq[N] = k;
        keys[k] = key;
        swim(N);
    }

    int operator[](int i){
        return keys[i];
    }
    int min(){
        return keys[pq[1]];
    }

    int pop_min(){
        if(n == 0){
            cout << "priority queue underflow" << endl;
            return numeric_limits<int>::min();
        }
        int indexOfMin = pq[1];
        exchange(1, N--);
        sink(1);
        keys[pq[N+1]] = 0;
        qp[pq[N+1]] = -1;
        return indexOfMin;
    }
private:
    int N;
    //二叉堆
    vector<int> pq;
    //为了能快速找到索引，创建一个qp数组
    vector<int> qp;
    //实际保存元素的数组。
    vector<int> keys;
};
