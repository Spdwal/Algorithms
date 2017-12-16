#include"MergeSorted.hpp"
#include"MergeBU.hpp"
#include<iostream>
#include<random>
using namespace std;

int main()
{
    random_device rd;
    uniform_int_distribution<int> dist(1, 100);
    vector<int> ivec;
    for(int i = 0; i < 20; i++){
        ivec.push_back(dist(rd));
    }

    vector<int> tmp = MergeBU(ivec);

    for(auto c : tmp){
        cout << c << endl;
    }
}
