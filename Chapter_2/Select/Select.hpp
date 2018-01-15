#include<vector>
#include<algorithm>
using namespace std;


int Partition(vector<int> &ivec, int low, int high)
{
    int i = low;
    int j = high+1;
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
int Select(vector<int> &ivec, int k)
{
    random_shuffle(ivec.begin(), ivec.end());
    int low = 0;
    int high = ivec.size() - 1;
    while(high > low){
        int j = Partition(ivec, low, high);
        if((j + 1) == k){
            return ivec[j];
        }else if(j > k){
            high = j - 1;
        }else if(j < k){
            low = j + 1;
        }
    }

    return ivec[k];
}
