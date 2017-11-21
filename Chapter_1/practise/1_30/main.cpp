#include<iostream>
#include<vector>
using namespace std;

int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }else
    {
        return gcd(b, a%b);
    }
}

int main()
{
    vector<vector<bool>> ivec(70, vector<bool>(70));
    for(int i = 0; i < ivec.size(); ++i)
    {
        for(int j = 0; j < ivec[0].size(); ++j)
        {
            if(gcd(i, j) == 1)
            {
                ivec[i][j] = false;
            }else
                ivec[i][j] = true;
        }
    }

    for(int i = 0; i < ivec.size(); ++i)
    {
        for(int j = 0; j < ivec[i].size(); ++j)
        {
            if(i == 0 || j == 0)
            {
                cout << ' ';
            }else if(ivec[i][j] == true)
            {
                cout << '*';
            }else{
                cout << ' ';
            }
        }
        cout << endl;
    }
}
