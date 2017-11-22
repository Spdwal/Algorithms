#include<vector>
#include<iostream>
#include<algorithm>
#include<iterator>
using namespace std;

void printVector(const vector<int>& ivec)
{
    for(auto c: ivec)
    {
        cout << c << endl;
    }
}

void init(vector<int>&ivec)
{
    sort(ivec.begin(), ivec.end());
}

void anay(vector<vector<float>> &vec, vector<int> ivec)
{
    for(int i = 0; i < ivec.size(); ++i)
    {
        vec[ivec[i]][i] += 1;
    }
}
int main()
{
    vector<int> ivec { 0,1,2,3,4,5,6,7,8,9};
    random_shuffle(ivec.begin(), ivec.end());
    printVector(ivec);
    vector<vector<float>>vec(10, vector<float>(10));
    for(int i = 0; i <10000000; ++i)
    {
        init(ivec);
        random_shuffle(ivec.begin(), ivec.end());
        anay(vec, ivec);
    }

    for(auto sub : vec)
    {
        copy(sub.begin(), sub.end(), ostream_iterator<float>(cout, "  "));
        cout << endl;
    }
    return 0;
}
