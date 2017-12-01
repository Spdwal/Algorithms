#include"getLessNeighborMartix.hpp"
#include<vector>
#include<iostream>
using namespace std;

int main()
{
	vector<vector<int>> ivec={{1,2,3,4,5,6,7},
							  {8,9,10,11,12,13,14},
							  {15,16,17,18,19,20,21}};

	pair<int, int> pos = getLessNeighborMatrix(ivec);

	cout << pos.first << endl <<  pos.second << endl;

	return 0;
}
