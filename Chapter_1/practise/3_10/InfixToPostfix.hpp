#include<string>
#include<sstream>
#include<stack>
using namespace std;

string InfixToPostfix(string str)
{
	ostringstream os;
	char c;
	stack<string> numberStack;
	stack<string> sStack;
	stack<string> oprStack;
	string right;
	string left;
	string opr;
	string s;
	for(int i = 0; i < str.size(); ++i)
	{
		if(str[i] == ')')
		{
			sStack.push(string(1,')'));
		}else if(str[i] == '.' || (str[i] > '0' || str[i] < '9')){
			os << str[i];
			c = str[i+1];
			if(!(c=='.' || (c >= '0' && c <y
