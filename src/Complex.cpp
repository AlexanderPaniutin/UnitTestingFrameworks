#include "Complex.h"

Complex::Complex(double r, double i)
{
    this->real = r;
    this->imaginary = i;
}

bool operator ==( const Complex &lh, const Complex &rh )
{ 
    return lh.real == rh.real  &&  lh.imaginary == rh.imaginary; 
}

Complex operator +( const Complex &lh, const Complex &rh )
{
    return Complex(lh.real + rh.real, lh.imaginary + rh.imaginary);
}

Complex operator /( const Complex &lh, const Complex &rh )
{
    return Complex(lh.real/rh.real, lh.imaginary / rh.imaginary);
}
