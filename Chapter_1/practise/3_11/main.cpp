#include<iostream>
#include<sstream>
#include<stack>
#include<string>
#include<utility>

using namespace std;

pair<float, float> toVal(stack<float> &stk)
{
    float right = stk.top();
    stk.pop();
    float left = stk.top();
    stk.pop();
    return make_pair(left, right);
}
bool isNumber(char c)
{
    return (c =='.' || (c >= '0' && c <= '9'));
}

double EvaluatePostfix(const string &str)
{
    stack<float> valStack;
    ostringstream os;
    pair<float, float> myPair;
    for(int i = 0; i < str.size(); ++i)
    {
        if(isNumber(str[i]))
        {
            os << str[i];
            if(!isNumber(str[i+1]))
            {
                valStack.push(stof(os.str()));
                os.str("");
            }
        }else if(str[i] == '+')
        {
            myPair = toVal(valStack);
            valStack.push(myPair.first + myPair.second);
        }else if(str[i] == '-')
        {
            myPair = toVal(valStack);
            valStack.push(myPair.first - myPair.second);
        }else if(str[i] == '*'){
            myPair = toVal(valStack);
            valStack.push(myPair.first * myPair.second);
        }else if(str[i] == '/'){
            myPair = toVal(valStack);
            valStack.push(myPair.first / myPair.second);
        }

    }
    return valStack.top();
}


int main()
{
    string str = "1 2 3 * +";
    cout << EvaluatePostfix(str)<< endl;

    return 0;
}

