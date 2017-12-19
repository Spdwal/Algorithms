#pragma once
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int Partition(vector<int> &ivec, int low, int high)
{
    int i = low;
    int j = high + 1;
    int v = ivec[low];
    while(true){
        while(ivec[++i] < v) if(i == high) break;
        while(v < ivec[--j]) if(j == low) break;
        if(i >= j) break;
        std::swap(ivec[i], ivec[j]);
    }
    std::swap(ivec[low], ivec[j]);
    return j;
}

void QuickSort(vector<int> &ivec, int low, int high)
{
    stack<int> StkLow;

    stack<int> StkHigh;
    int pos = 0;
    if(low >= high) return;
    StkLow.push(low);
    StkHigh.push(high);
    do{
        int i = StkLow.top();
        int j = StkHigh.top();
        pos = Partition(ivec, i, j);
        StkLow.pop();
        StkHigh.pop();
        if(i < pos - 1){
            StkLow.push(i);
            StkHigh.push(pos - 1);
        }
        if(pos + 1 < j){
            StkLow.push(pos + 1);
            StkHigh.push(high);
        }
    }while(!StkLow.empty());
}
void QuickSort(vector<int> &ivec)
{
    random_shuffle(ivec.begin(), ivec.end());
    QuickSort(ivec, 0, ivec.size() - 1);
}
