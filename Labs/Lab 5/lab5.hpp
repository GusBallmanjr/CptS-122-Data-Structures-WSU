#pragma once

#include <iostream>

class ComplexNumbers
{
public:
	
	ComplexNumbers()
	{
		mRealPart = 0;
		mImaginaryPart = 0;
	};
	
	double getReal() const;
	double getImag() const;

	void setReal(const double real);
	void setImag(const double imag);

	ComplexNumbers add(ComplexNumbers num);
	void read();

	friend ComplexNumbers& operator+ (const ComplexNumbers & lhs, const ComplexNumbers & rhs);
private:
	double mRealPart, mImaginaryPart;
};

ComplexNumbers add(ComplexNumbers num1, ComplexNumbers num2);
ComplexNumbers subtract(ComplexNumbers lhs, ComplexNumbers rhs);
std::ostream& operator<<(std::ostream& lhs, ComplexNumbers& rhs);