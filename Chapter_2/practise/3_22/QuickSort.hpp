#pragma once
#include<vector>
#include<algorithm>
using namespace std;

const int INSERTION_SORT_CUTOFF = 8;
const int MEDIAN_OF_3_CUTOFF = 40;

void insertSort(vector<int> &ivec, int low, int high){
    for(int i = low; i <= high; ++i){
        for(int j = i; j > low && ivec[j] < ivec[j - 1]; --j){
            std::swap(ivec[j], ivec[j - 1]);
        }
    }
}
int median3(vector<int> &ivec, int i, int j, int k){
    return ((ivec[i] < ivec[j]) ?
            ((ivec[j] < ivec[k]) ? j : (ivec[i] < ivec[k]) ? k : i) :
            ((ivec[k] < ivec[j]) ? j : (ivec[k] < ivec[i]) ? k : i));
}

void QuickSort(vector<int> &ivec, int low, int high){
    int n = high - low + 1;

    if(n < INSERTION_SORT_CUTOFF){
        insertSort(ivec, low, high);
        return;
    }else if(n <= MEDIAN_OF_3_CUTOFF){
        int m = median3(ivec, low, low + n / 2, high);
        std::swap(ivec[m], ivec[low]);
    }else{
        int eps = n / 8;
        int mid = low + n / 2;
        int m1 = median3(ivec, low, low + eps, low + eps + eps);
        int m2 = median3(ivec, mid - eps, mid , mid + eps);
        int m3 = median3(ivec, high - eps - eps, high - eps, high);
        int ninther = median3(ivec, m1, m2, m3);
        std::swap(ivec[ninther], ivec[low]);
    }

    int i = low, j = high + 1;
    int p = low, q = high + 1;

    int v = ivec[low];

    while(true){
        while(ivec[++i] < v){
            if(i == high) break;
        }
        while(v < ivec[--j]){
            if(j == low) break;
        }

        if(i == j && ivec[i] == v){
            std::swap(ivec[++p], ivec[i]);
        }
        if(i >= j) break;

        std::swap(ivec[i], ivec[j]);
        if(ivec[i] == v) std::swap(ivec[++p], ivec[i]);
        if(ivec[j] == v) std::swap(ivec[--q], ivec[j]);
    }
    i = j + 1;
    for(int k = low; k <= p; k++){
        std::swap(ivec[k], ivec[j--]);
    }
    for(int k = high; k >= q; k--){
        std::swap(ivec[k], ivec[i++]);
    }
    QuickSort(ivec, low, j);
    QuickSort(ivec, i, high);
}
void QuickSort(vector<int> &ivec)
{
    random_shuffle(ivec.begin(), ivec.end());
    QuickSort(ivec, 0, ivec.size() - 1);
}
