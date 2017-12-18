#pragma once
#include<vector>
using namespace std;
void Fix(vector<int> &nuts, vector<int> &bolts, int low, int high)
{
    if(low >= high){
        return ;
    }
    int tmp = nuts[low];
    int i = low;
    int j = high + 1;
    int bolt_match =0;
    while(true){
        if(bolts[bolt_match] == tmp){
            std::swap(bolts[low], bolts[bolt_match]);
            break;
        }
        bolt_match++;
    }
    while(true){
        while(bolts[++i] < tmp){
            if(i == high){
                break;
            }
        }
        while(bolts[--j] > tmp){
            if(j == low){
                break;
            }
        }
        if(i >= j){
            break;
        }
        std::swap(bolts[i], bolts[j]);
    }

    std::swap(bolts[low], bolts[j]);
    tmp = bolts[j];
    i = low;
    j = high + 1;
    while(true){
        while(nuts[++i] < tmp){
            if(i == high){
                break;
            }
        }
        while(nuts[--j] > tmp){
            if(j == low){
                break;
            }
        }
        if(i >= j){
            break;
        }
        std::swap(nuts[i], nuts[j]);
    }
    std::swap(nuts[low], nuts[j]);
    
    Fix(nuts, bolts, low, j-1);
    Fix(nuts, bolts, j+1, high);
}

void Fix(vector<int> &nuts, vector<int> &bolts)
{
    Fix(nuts, bolts, 0, nuts.size() - 1);
}
