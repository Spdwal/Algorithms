#include<vector>
#include<iostream>
#include<algorithm>
#include<random>
using namespace std;

int binarySearch(const vector<int>& ivec, int search, int low, int high)
{
    int mid = (low + high) / 2;
    if (low >= high)
    {
        return ivec.size() + 1;
    }
    if(search > ivec[mid])
    {
        return binarySearch(ivec, search, mid + 1, high);
    }else if(search < ivec[mid])
    {
        return binarySearch(ivec, search, low, mid - 1);
    }else
        return mid;
}


int binarySearchRank(const vector<int> &ivec, int search)
{
    int low = 0;
    int high = ivec.size() - 1;
    return binarySearch(ivec, search, low, high);
}

int binarySearchFast(vector<int> &ivec)
{
    sort(ivec.begin(), ivec.end());
    int N = ivec.size();
    int count = 0;
    for(int i = 0; i < N; ++i)
    {
        int result = binarySearchRank(ivec, - ivec[i]);
        if(result > i && result <= N)
        {
            ++ count;
        }
    }
    return count;
}
int main()
{
    vector<int> ivec;
    std::default_random_engine e1;
    std::uniform_int_distribution<int> di(-1000000, 100000);
    for(int i = 0; i < 100000; ++i)
    {
        ivec.push_back(di(e1));
    }

    cout << binarySearchFast(ivec) << endl;

    return 0;
}
