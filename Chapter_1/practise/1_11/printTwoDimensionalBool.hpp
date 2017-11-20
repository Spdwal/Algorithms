#include<vector>
#include<iostream>
using namespace std;

void printTwoDimensionalBool(vector<vector<bool>> ivec)
{
    cout << "col ";
    for(int i = 0; i < ivec[0].size(); i++)
    {
        cout << i+1 << ' ';
    }
    cout << endl;

    for(int i = 0; i < ivec.size(); i++)
    {
        cout << i+1 << "    ";
        for(auto c : ivec[i])
        {
            if(c == true)
            {
                cout << '*' << ' ';
            }else{
                cout << "  ";
            }
        }
        cout << endl;
    }
}
