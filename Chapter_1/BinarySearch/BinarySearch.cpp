#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int Rank(int key, const vector<int> &ivec)
{
    int lo = 0;
    int hi = ivec.size() - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if(key < ivec[mid])
        {
            hi = mid - 1;
        }else if(key > ivec[mid])
        {
            lo = mid + 1;
        }else
            return key;
    }
    return -1;
}

int main()
{
    vector<int> ivec;
    cout << "input the elements of vec";
    int num = 1;
    while(num != 0)
    {
        cin >> num;
        ivec.push_back(num);
    }
    sort(ivec.begin(), ivec.end());
    int key = -1;
    cout << "input the key:";
    cin >> key;
    int pos = Rank(key, ivec);
    if(pos == -1)
    {
        cout << "Can't find the key" << endl;
    }else{
        cout << "The position is " << pos << endl;
    }
    return 0;
}
