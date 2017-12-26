#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;

vector<int> CubeSum(int i, int j)
{
    vector<int> ivec;
    ivec.push_back(pow(i, 3) + pow(j, 3));
    ivec.push_back(i);
    ivec.push_back(j);
    return ivec;
}

auto cmp = [] (const vector<int> &lhs, const vector<int> &rhs)
{
    return lhs[0] > rhs[0];
};

int main()
{
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> que(cmp);
    for(int i = 0; i < 10; ++i){
        que.push(CubeSum(i, 0));
    }
    int j = 0;

    while(!que.empty()){
        vector<int> tmp = que.top();
        cout << "sum: " << tmp[0] << endl;
        cout << "i:   " << tmp[1] << endl;
        cout << "j:   " << tmp[2] << endl;
        que.pop();
        if(j < 10){
            que.push(CubeSum(tmp[1], j++));
        }
    }
    cout << endl;
    return 0;
}
