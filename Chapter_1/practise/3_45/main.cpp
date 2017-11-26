#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool isOverFlow(const vector<char> &ivec)
{
    int myCount = 0;
    
    for(auto c : ivec)
    {
        if(c != '-')
        {
            myCount ++;
        }else{
            myCount --;
        }
        if(myCount >= 0)
        {
            continue;
        }else
        {
            return false;
        }
    }
    return true;
}
//判断 能不能使用栈从from生成序列to
bool isGereratorTO(const vector<int> ivecFrom, const vector<int> ivecTo)
{
    stack<int> stk;
    stk.push(ivecFrom[0]);
    auto itr = ivecTo.begin();
    int i = 1;
    while(true)
    {
        if(stk.empty())
        {
            if(itr == (ivecTo.end() - 1))
            {
                if(i == ivecFrom.size() - 1)
                {
                    return true;
                }else{
                    return false;
                }
            }else{
                stk.push(ivecFrom[i]);
                i++;
            }
        }
        else if(stk.top() != *itr)
        {
            stk.push(ivecFrom[i]);
            ++i;
        }else{
            itr++;
            stk.pop();
        }
    }
}
int main()
{
    vector<char> ivec {'1', '2', '3', '4', '5', '-', '-', '-', '-', '-', '-'};
    cout << boolalpha << isOverFlow(ivec) << endl;

    vector<int> vecInt;
    for(int i = 0; i < 10; ++i)
    {
        vecInt.push_back(i);
    }

    vector<int> vecIntTo{5,4,3,2,1,0,9,8,7,6,7};
    cout << boolalpha << isGereratorTO(vecInt, vecIntTo) << endl;

    vecInt.push_back(5);
    cout << boolalpha << isGereratorTO(vecInt, vecIntTo) << endl;
    return 0;
}
