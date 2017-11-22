#include<iostream>
#include<iomanip>
using namespace std;

class Rational{
public:
    Rational(float num = 0, float den = 0): numerator{num}, denominator{den} {}
    Rational(const Rational & rhs): numerator{rhs.numerator}, denominator{rhs.denominator} {}
    Rational& operator=(Rational rhs)
    {
        Rational temp(rhs);
        std::swap(temp, *this);
        return *this;
    }
    friend Rational operator+(const Rational &lhs, const Rational &rhs)
    {
        return Rational(lhs.numerator + rhs.numerator, lhs.denominator+ rhs.denominator);
    }
    friend Rational operator-(const Rational &lhs, const Rational &rhs)
    {
        return Rational(lhs.numerator - rhs.numerator, lhs.denominator - rhs.denominator);
    }
    friend Rational operator*(const Rational &lhs, const Rational &rhs)
    {
        return Rational(lhs.numerator * rhs.numerator - lhs.denominator * rhs.denominator,
                        lhs.numerator * rhs.denominator + lhs.denominator * rhs.numerator);
    }
    friend Rational operator/(const Rational &lhs, const Rational &rhs)
    {
        float powerAdd = rhs.numerator * rhs.numerator +
            rhs.denominator * rhs.denominator;
        return Rational((lhs.numerator * rhs.numerator + lhs.denominator * rhs.denominator) / powerAdd,
                        (lhs.denominator * rhs.numerator - lhs.numerator * rhs.denominator) / powerAdd);
    }
    friend bool operator==(const Rational &lhs, const Rational &rhs)
    {
        return (lhs.numerator == rhs.numerator && rhs.denominator == lhs.denominator);
    }
    friend ostream& operator<<(ostream &out, const Rational &rhs)
    {
        cout << rhs.numerator << showpos << rhs.denominator << 'i' << resetiosflags(ios::showpos);
    }
private:
    float numerator;
    float denominator;
};
