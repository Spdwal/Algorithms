#include"toBinaryString.hpp"
#include<string>
#include<iostream>
using namespace std;
int main()
{
	int num  = 0;
    while(cin >> num)
    {
        cout << toBinaryString(num) << endl;
    }

	return 0;
}
