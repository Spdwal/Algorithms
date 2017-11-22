#include<vector>
#include<iostream>
#include<random>
using namespace std;
vector<float> dist()
{
    int sides = 6;
    vector<float> result(sides*2 + 1);
    for(int i = 1; i <= sides; ++i)
    {
        for(int j = 1; j < sides; ++j)
        {
            result[i+j] +=1;
        }
    }
    return result;
}
int main()
{
    vector<float> ivec = dist();
    for(auto &c : ivec)
    {
        c /=36;
        cout << c <<" ";
    }
    cout << endl;
    std::default_random_engine dre;
    std::uniform_int_distribution<int> di(1, 6);

    cout << "the next:  " << endl;;
    vector<float> tmp(13);
    for(int i = 0; i < 100000000; ++i)
    {
        tmp[di(dre) + di(dre)] += 1;
    }

    for(auto c : tmp)
    {
        c /= 100000000;
        cout << c << " ";
    }
    cout << endl;
    return 0;
}
