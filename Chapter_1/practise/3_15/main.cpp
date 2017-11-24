#include<iostream>
#include<queue>
using namespace std;

int main(int argc, char *argv[])
{
	queue<string> strQue;
	string str;
	while(cin >> str)
	{
		strQue.push(str);
	}
	cout << argv[1] << endl;
	int i = stod(argv[1]);

	while(i > 1)
	{
		strQue.pop();
		i--;
	}

	cout << strQue.front() << endl;
	return 0;
}
