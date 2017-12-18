#include"NAndB.hpp"
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void Display(const vector<int> &ivec, const string &str)
{
    cout << str << endl;
    for(auto c : ivec){
        cout << c << endl;
    }
}
int main()
{
    vector<int> nuts;
    vector<int> bolts;
    for(int i = 1; i < 10; ++i){
        nuts.push_back(i);
        bolts.push_back(i);
    }

    random_shuffle(nuts.begin(), nuts.end());
    random_shuffle(bolts.begin(), bolts.end());
    Display(nuts, "nuts:");
    Display(bolts, "bolts:");

    Fix(nuts, bolts);

    Display(nuts, "nuts:");
    Display(bolts, "bolts:");

    return 0;
}
