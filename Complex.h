#ifndef COMPLEX_H
#define COMPLEX_H
#include <cmath>

class Complex {
private:
    double _r;
    double _im;
public:
    Complex(double r = 0, double im = 0) : _r(r), _im(im) {}
    Complex(const Complex& c) {
        _r = c._r;
        _im = c._im;
    }
    double Re() const { return _r; }
    double Im() const { return _im; }
    double ModSquar() const { return _r * _r + _im * _im; }
    double Mod() const { return std::sqrt(ModSquar()); }
    Complex operator+(const Complex &rhs) const {return Complex(_r + rhs._r, _im + rhs._im); }
    Complex operator-() const {return Complex(-_r, -_im); }
    Complex operator*(const Complex &rhs) const {return Complex(_r * rhs._r - _im * rhs._im, _r * rhs._im + rhs._r * _im); }
    Complex operator*(const double value) const {return Complex(_r * value, _im * value); }
    Complex operator/(const double value) const {return Complex(_r / value, _im / value); }
    Complex operator/(const Complex &rhs) const {
        double modSquar = rhs.ModSquar();
        if (modSquar == 0)
            throw std::overflow_error("Divide by zero exception");
        return Complex((_r * rhs._r + _im * rhs._im) / modSquar, (rhs._r * _im - _r * rhs._im) / modSquar);
    }
    bool operator==(const Complex &rhs) const { return (_r == rhs._r && _im == rhs._im); }
};

#endif
