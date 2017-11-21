#include<iostream>
using namespace std;
int fac(int m)
{
    if(m == 1)
    {
        return 1;
    }else{
        return m* fac(m - 1);
    }
}

int main()
{
    cout << fac(5) << endl;
}

