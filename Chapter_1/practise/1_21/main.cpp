#include<iostream>
#include<cstdio>
#include<vector>
#include<tuple>
#include<string>
#include<iomanip>
using namespace std;

void RecieveAndPrint()
{
	vector<tuple<string, int, int, float>> ivec;
	string name;
	int num1, num2;

	while(cin >> name >> num1 >> num2)
	{
		ivec.push_back(make_tuple(name, num1, num2, static_cast<float>(num1)/num2));
	}

	for(auto c : ivec)
	{
		printf("%10s|%5d|%5d|%10.3f|\n",get<0>(c).c_str(), get<1>(c), get<2>(c), get<3>(c));
	}
	cout << setfill('-') << setw(20) << endl;
}

int main()
{
	RecieveAndPrint();
	return 0;
}
