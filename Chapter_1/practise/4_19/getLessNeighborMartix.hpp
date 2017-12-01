#pragma once
#include<vector>
#include<utility>
#include<string>
using namespace std;



pair<int, int> max2(const vector<vector<int>> &ivec, pair<int, int> pos1, pair<int, int> pos2)
{
    if(ivec[pos1.first][pos1.second] > ivec[pos2.first][pos2.second])
    {
        return make_pair(pos1.first, pos1.second);
    }else if(ivec[pos1.first][pos1.second] < ivec[pos2.first][pos2.second]){
        return make_pair(pos2.first, pos2.second);
    }
}

pair<int, int> max3(const vector<vector<int>> &ivec, pair<int, int> pos1, pair<int, int> pos2, pair<int, int> pos3)
{
    return max2(ivec, pos1, max2(ivec, pos2, pos3));
}

pair<int, int> max4(const vector<vector<int>> &ivec, pair<int, int> pos1, pair<int, int> pos2, pair<int, int> pos3, pair<int, int> pos4)
{
    return max2(ivec, pos1, max3(ivec, pos2, pos3, pos4));
}

pair<int, int> max5(const vector<vector<int>> &ivec, pair<int, int> pos1, pair<int, int> pos2, pair<int, int> pos3, pair<int, int> pos4, pair<int, int> pos5)
{
    return max2(ivec, pos1, max4(ivec, pos2, pos3, pos4, pos5));
}

pair<int, int> getLessNeighborMatrix(const vector<vector<int>> &ivec)
{
    int rowSize = ivec.size() - 1;
    int colSize = ivec[0].size() - 1;
    int i = 0;
    int j = 0;
    pair<int, int>  currentPos = make_pair(0, 0);
    pair<int, int>  nextPos = make_pair(-1, -1);
    while(true)
    {
        pair<int, int> Up    = make_pair(currentPos.first - 1, currentPos.second);
        pair<int, int> Down  = make_pair(currentPos.first + 1, currentPos.second);
        pair<int, int> Left  = make_pair(currentPos.first, currentPos.second - 1);
        pair<int, int> Right = make_pair(currentPos.first, currentPos.second + 1);

        if(currentPos.first == 0 && currentPos.second == 0){
            nextPos = max3(ivec, currentPos, Right, Down);
        }else if(currentPos.first ==0 && currentPos.second == colSize)
        {
            nextPos = max3(ivec, currentPos,Left, Down);
        }else if(currentPos.first == rowSize && currentPos.second == 0)
        {
            nextPos = max3(ivec, currentPos, Up, Right);
        }else if(currentPos.first == rowSize && currentPos.second == colSize)
        {
            nextPos = max3(ivec, currentPos, Up, Left);
        }else if(currentPos.first == 0)
        {
            nextPos = max4(ivec, currentPos, Down, Left, Right);
        }else if(currentPos.first == rowSize){
            nextPos = max4(ivec, currentPos, Up, Left, Right);
        }else if(currentPos.second == 0){
            nextPos = max4(ivec, currentPos, Up, Right, Down);
        }else if(currentPos.second == colSize){
            nextPos = max4(ivec, currentPos, Up, Left, Down);
        }else{
            nextPos = max5(ivec, currentPos, Up, Down, Left, Right);
        }

        
        if(currentPos == nextPos)
        {
            return currentPos;
        }else{
            currentPos =nextPos;
        }

    }
}

