#include<iostream>
#include"Matrix.hpp"

using namespace std;

int main()
{
	Matrix m = {{1,2,3}, {4,5,6}};
    Matrix a = m;
	cout << m;
	m.transpose();
	cout << m;
    cout << a << endl;
    
    Matrix tmp = a * m;
    cout << tmp <<endl;

    return 0;
}
