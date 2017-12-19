#pragma once
#include<vector>
#include<algorithm>
using namespace std;

int partition(vector<int> &ivec, int low, int high)
{
    int i = low;
    int j = high + 1;
    int v = ivec[low];

    while(true){
        while(ivec[++i] < v);
        while(v < ivec[--j]);
        if(i >= j) break;
        std::swap(ivec[i], ivec[j]);
    }
    std::swap(ivec[low], ivec[j]);
    return j;
}
int find_max(const vector<int> &ivec)
{
    int Max = ivec[0];
    int pos = 0;
    for(int i = 1; i < ivec.size(); ++i){
        if(ivec[i] > Max){
            Max = ivec[i];
            pos = i;
        }
    }

    return pos;
}
void QuickSort(vector<int> &ivec, int low, int high)
{
    if(low >= high) return ;
    int j = partition(ivec, low, high);
    QuickSort(ivec, low, j - 1);
    QuickSort(ivec, j+1, high);
}

void QuickSort(vector<int> &ivec)
{
    random_shuffle(ivec.begin(), ivec.end());
    int Max = find_max(ivec);
    std::swap(ivec[Max], ivec[ivec.size() - 1]);
    QuickSort(ivec, 0, ivec.size() - 1);
}
