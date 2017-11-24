#include<iostream>
#include<list>
#include<stack>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	string str = "1 + 2 ) * 3 - 4) * 5 - 6) ) )";
	stack<string> sStack;
	ostringstream os;
	string myRight;
	string myLeft;
	string myOpr;
	char c;
	for(int i = 0 ; i < str.size(); ++i)
	{
		switch(str[i])
		{
		case ')':
			myRight = sStack.top();
			sStack.pop();
			myOpr = sStack.top();
			sStack.pop();
			myLeft = sStack.top();
			sStack.pop();
            sStack.push("(" + myLeft + myOpr + myRight + ")");
		case ' ':
			continue;
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.':
			c = str[i + 1];
			os << str[i];
			if(!(c == '.' || (c >= '0' && c <= '9')))
			{
				sStack.push(os.str());
				os.str("");
			}
			break;
		default:
			sStack.push(string(1,str[i]));
			break;
		}
	}
	cout << sStack.top() << endl;
}
