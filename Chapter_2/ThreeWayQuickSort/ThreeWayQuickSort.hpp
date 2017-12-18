#pragma once
#include<vector>
#include<algorithm>
using namespace std;

void QuickSort(vector<int> &ivec, int low, int high)
{
    if(high <= low) return;

    int Lt = low;
    int i = low + 1;
    int gt = high;
    int v = ivec[low];
    while(i <= gt){
        if(ivec[i] < v){
            std::swap(ivec[Lt++], ivec[i++]);
        }else if(ivec[i] > v){
            std::swap(ivec[i], ivec[gt--]);
        }else{
            i++;
        }
    }
    QuickSort(ivec, low, Lt - 1);
    QuickSort(ivec, gt + 1, high);
}
void QuickSort(vector<int> &ivec)
{
    random_shuffle(ivec.begin(), ivec.end());
    QuickSort(ivec, 0, ivec.size() - 1);
}


