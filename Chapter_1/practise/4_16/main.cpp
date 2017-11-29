#include<iostream>
#include<vector>
#include"closePair.hpp"
using namespace std;

int main()
{
	vector<double>ivec{1.1,3.3,2.5,9.9,3.4,5.2};

	pair<double, double> myPair = closePair(ivec);

	cout << myPair.first << " " << myPair.second << endl;

	return 0;
}
