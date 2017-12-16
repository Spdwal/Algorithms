#include"MergeSorted.hpp"
#include<vector>
#include<queue>
using namespace std;

vector<int> MergeBU(vector<int> ivec)
{
    queue<vector<int>> myQue;
    for(auto c : ivec){
        myQue.push(vector<int>{c});
    }

    while(myQue.size() != 1){
        vector<int> tmpVec = myQue.front();
        myQue.pop();
        vector<int> Front = myQue.front();
        vector<int> pushVec = MergeSorted(Front, tmpVec);
        myQue.push(pushVec);
        myQue.pop();
    }
    vector<int> Vec = myQue.front();
    return Vec;
}
