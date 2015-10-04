
class Complex
{
    public:
        Complex(double r, double i=0);
        
    private:
        friend bool operator ==(const Complex &lh, const Complex &rh);
        friend Complex operator +(const Complex &lh, const Complex &rh);
        friend Complex operator /(const Complex &lh, const Complex &rh);
        double real;
        double  imaginary;
};
