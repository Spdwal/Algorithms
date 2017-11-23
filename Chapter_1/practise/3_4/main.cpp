#include<stack>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string line;
    while(cin >> line)
    {
        stack<char> s;
        for(int i = 0; line[i] != '\0'; i++) 
        {
            char c = line[i];
            switch(c)
            {
                case '[':
                case '{':
                case '(':
                    s.push(c);
                    break;
                case ']':
                    if(s.top() == '[')
                    {
                        s.pop();
                        break;
                    }else
                        goto label;
                case ')':
                    if(s.top()=='(')
                    {
                        s.pop();
                        break;
                    }else
                        goto label;
                case '}':
                    if(s.top()=='{')
                    {
                        s.pop();
                        break;
                    }else
                        goto label;
                default:
                    goto label;
            }
        }
        cout << "true" << endl;
        continue;
    label:
        cout << "false" << endl;
    }

    return 0;
}
