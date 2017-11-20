#include"printTwoDimensionalBool.hpp"
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<vector<bool>> ivc = {{true, true, true, false},
								{false, false, false, true},
								{true, true, false, false}};

	printTwoDimensionalBool(ivc);

	return 0;
}
