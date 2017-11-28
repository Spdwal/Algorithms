#include"findSubElements.hpp"
#include<iostream>
using namespace std;

int main()
{
	vector<int> ivec1 { 1,2,3,4,5,6,7,8,9};

	vector<int> ivec2 {5,6,7,8,9,10,11};

	vector<int> ivec = findSubElements(ivec1, ivec2);

	for(auto c : ivec)
	{
		cout << c << endl;
	}
}
