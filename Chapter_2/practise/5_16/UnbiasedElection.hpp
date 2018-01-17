#pragma once
#include<map>
#include<algorithm>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;


class Name{
public:
    Name() = default;
    Name(const char* str): name(str) {}
    Name(const string &str): name(str){}
    bool operator<(const Name &rhs){
        int lsize = name.size();
        int rsize = rhs.name.size();
        int mySize = min(lsize, rsize);
        for(int i = 0; i < mySize; ++i){
            if(name[i] == rhs.name[i]){
                continue;
            }else if(iMap[toupper(name[i])] < iMap[toupper(rhs.name[i])]){
                return true;
            }else
                return false;
        }
        if(lsize > rsize)
            return false;
        else
            return true;
    }

    bool operator==(const Name &rhs){
        return name == rhs.name;
    }

    bool operator>(const Name &rhs){
        return !((*this < rhs) || (*this == rhs));
    }

    friend istream& operator>> (istream &is, Name &rhs);
    friend ostream& operator<< (ostream &os, const Name &rhs);
private:
    static map<char, int> iMap;
    string name;
};

istream& operator>> (istream &is, Name &rhs)
{
    is >> rhs.name;
    return is;
}

ostream& operator<< (ostream &os, const Name &rhs)
{
    os << rhs.name;
    return os;

}




map<char, int> Name::iMap {{'R', 1},
    {'W', 2},
    {'Q', 3},
    {'O', 4},
    {'J', 5},
    {'M', 6},
    {'V', 7},
    {'A', 8},
    {'H', 9},
    {'B', 10},
    {'S', 11},
    {'G', 12},
    {'Z', 13},
    {'X', 14},
    {'N', 15},
    {'T', 16},
    {'C', 17},
    {'I', 18},
    {'E', 19},
    {'K', 20},
    {'U', 21},
    {'P', 22},
    {'D', 23},
    {'Y', 24},
    {'F', 26},
    {'L', 27},};
                                                                                        
