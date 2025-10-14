#include "lab5.hpp"

double ComplexNumbers::getReal() const
{
    return mRealPart;;
}

double ComplexNumbers::getImag() const
{
    return mImaginaryPart;
}

void ComplexNumbers::setReal(const double real)
{
    mRealPart = real;
}

void ComplexNumbers::setImag(const double imag)
{
    mImaginaryPart = imag;
}

ComplexNumbers ComplexNumbers::add(ComplexNumbers num)
{
    mImaginaryPart += num.mImaginaryPart;
    mRealPart += num.mRealPart;
    return ComplexNumbers();
}

void ComplexNumbers::read()
{
    double real = 0.0, imag = 0.0;
    char garb = '\0';
    std::cout << "Enter in the values of complex number in the form a + bi: " << std::endl;
    std::cin >> real >> garb >> imag >> garb;
    setReal(real);
    std::cout << "Enter in imaginary part of complex number: " << std::endl;
    std::cin >> imag;
    setReal(imag);
}

ComplexNumbers& operator+ (const ComplexNumbers& lhs, const ComplexNumbers& rhs)
{
    ComplexNumbers result;

    result.setReal(lhs.getReal() + rhs.getReal());
    result.setImag(lhs.getImag() + rhs.getImag());

    return result;
}