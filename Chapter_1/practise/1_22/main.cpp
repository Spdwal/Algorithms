#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int BinarySearch(const vector<int> &ivec, int high, int low, int searched)
{
    int mid = (high + low) / 2;
    if(searched > ivec[mid])
    {
        return BinarySearch(ivec, high, mid, searched);
    }else if(searched < ivec[mid])
    {
        return BinarySearch(ivec, mid, low, searched);
    }else
        return mid;
}


int main()
{
    vector<int> ivec;
    int num;
    while(cin >> num)
    {
        ivec.push_back(num);
    }
    sort(ivec.begin(), ivec.end());

    cout << BinarySearch(ivec, ivec.size(), 0, 5) << endl;

    return 0;
}
