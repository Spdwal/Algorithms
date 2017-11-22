#include"Rational.hpp"
#include<iostream>

int main()
{
	Rational R1(1,1);
	cout << R1 << endl;
	Rational R2(2, 4);
	cout << R2 << endl;
	Rational R3 = R1+R2;
	cout << R3 << endl;
	return 0;
}
