#include<iostream>
#include<sstream>
#include<string>
#include<stack>
using namespace std;

int main()
{
    stack<string> ops;
    stack<string> vals;
    ostringstream os;
    string str = "(((1+2.5)*3)+((2+3)*4))";
    for(int i = 0; i < str.size(); ++i)
    {
        char c = str[i];
        if(c == '(')
        {
            continue;
        }else if(c == '+' || c == '-')
        {
            ops.push(string(1, c));
        }else if(c== '*' || c == '/')
        {
            ops.push(string(1, c));
        }else if(c == ')')
        {
            string op = ops.top();
            ops.pop();
            string v = vals.top();
            vals.pop();
            v = vals.top() + " " + v + " " + op;
            vals.pop();
            vals.push(v);
        }else if(c == '.' || (c >= '0' && c <= '9')){
            os << c;
            if(!(str[i+1] == '.' || (str[i+1] >= '0' && str[i+1] <= '9')))
            {
                vals.push(os.str());
                os.str("");
            }
        }
    }
    cout << vals.top() << endl;
}
