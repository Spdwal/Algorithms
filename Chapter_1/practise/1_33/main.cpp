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
    cout << m[1][1] << endl;
    cout << a << endl;
    
    Matrix tmp = a * m;
    cout << tmp <<endl;

    vector<int> ivec = {1,2,3};
    Matrix c{ivec};
    cout << m << endl;
    cout << ivec.size() << a.cols()<< endl;
    c = ivec * a;
    cout << c << endl;
	return 0;
}
