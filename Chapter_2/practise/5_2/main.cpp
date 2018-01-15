#include"Print.hpp"
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    vector<string> ivec{"hello", "world", "helloworld", "name", "space", "namespace", "good", "night", "goodmorning", "worldhello"};

    vector<string> ivec2 = FindCompound(ivec);
    for(const auto & c: ivec2){
        cout << c << endl;
    }

    return 0;
}
