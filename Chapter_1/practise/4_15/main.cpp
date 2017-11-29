#include"threeSumFast.hpp"
#include<vector>
#include<iostream>
using namespace std;


int main()
{
	vector<int> ivec;

	for(int i = -5; i < 10; ++i)
	{
		ivec.push_back(i);
	}

	cout << twoSumFast(ivec) << endl;

	cout << threeSumFast(ivec) << endl;
}
