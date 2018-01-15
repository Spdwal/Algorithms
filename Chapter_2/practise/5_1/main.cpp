#include"StrCmp.hpp"
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str1 = "123";
    string str2 = "124";
    string str3 = "1234";
    cout << StrCmp(str1, str2) << endl;
    cout << StrCmp(str1, str3) << endl;
    cout << StrCmp(str3, str2) << endl;
    cout << StrCmp(str1.c_str(), str2.c_str()) << endl;
    cout << StrCmp(str1.c_str(), str2.c_str()) << endl;
    cout << StrCmp(str3.c_str(), str2.c_str()) << endl;

    return 0;
}
