#include"histogram.hpp"
#include<vector>
#include<iostream>
int main()
{
	std::vector<int> ivec{1,2,3,4,5,6,7,4,5,6,7,9};
	std::vector<int> temp = histogram(ivec, 10);

	for(auto c : temp)
	{
		std::cout << c << std::endl;
	}

	return 0;
}
