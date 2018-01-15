#pragma once
#include<string>
#include<cstring>

using namespace std;

int StrCmp(const char* str1, const char* str2)
{
    if(str1 == str2) return 0;
    int size1 = strlen(str1);
    int size2 = strlen(str2);
    int n = max(size1, size2);
    for(int i = 0; i < n; i++){
        if(str1[i] < str2[i])
            return -1;
        else if(str1[i] > str2[i])
            return 1;
    }
    if(size1 == size2)
        return 0;
    else if(size1 > size2)
        return 1;
    else
        return -1;
}

int StrCmp(const string &str1, const string &str2)
{
    if(str1 == str2) return 0;
    int size1 = str1.size();
    int size2 = str2.size();
    int n = max(size1, size2);
    for(int i = 0; i < n; ++i){
        if(str1[i] < str2[i]){
            return -1;
        }else if(str2[i] > str2[i]){
            return 1;
        }
    }
    if(size1 == size2)
        return 0;
    else if(size1 > size2)
        return 1;
    else
        return -1;
}
