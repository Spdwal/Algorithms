#include<vector>
using namespace std;

vector<int> histogram(const vector<int> &ivec, int m)
{
	vector<int> mvec(m);
	for(auto c : ivec)
	{
		mvec[c]++;
	}
	return mvec;
}
