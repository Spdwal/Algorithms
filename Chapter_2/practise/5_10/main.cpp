#include"Version.hpp"
#include<iostream>

int main()
{
    Version V1(115,10,11);
    Version V2(115, 1, 20);

    cout << V1.get() << endl;
    cout << V2.get() << endl;

    cout << boolalpha << (V1 < V2) << endl;
}
