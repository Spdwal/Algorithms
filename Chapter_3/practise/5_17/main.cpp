#include"MathSet.hpp"
#include<iostream>

using namespace std;

int main()
{
    MathSet<int> ms;
    for(int i = 0; i < 10; i++){
        ms.insert(i);
    }

    MathSet<int> rhs;
    rhs.insert(10);
    rhs.insert(3);
    rhs.insert(13);

    ms.intersection(rhs);
    //ms.math_union(rhs);
    ms.print();
    //ms.erase(9);
    
}
