#include"dedup.hpp"
#include<iostream>
using namespace std;

int main(){
    vector<string> ivec{ "hello", "world", "name", "zelda", "fuck", "vector", "hello", "zelda", "mario"};
    vector<string> ivec2 = dedup(ivec);
    for(auto &c : ivec2){
        cout << c << endl;
    }

    return 0;
}
