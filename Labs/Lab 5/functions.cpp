#include "lab5.hpp"

ComplexNumbers add(ComplexNumbers lhs, ComplexNumbers rhs)
{
	ComplexNumbers result;

	result.setReal(lhs.getReal() + rhs.getReal());
	result.setImag(lhs.getImag() + rhs.getImag());

	return result;
}

ComplexNumbers subtract(ComplexNumbers lhs, ComplexNumbers rhs)
{
	ComplexNumbers result;

	result.setReal(lhs.getReal() - rhs.getReal());
	result.setImag(lhs.getImag() - rhs.getImag());

	return result;
}

std::ostream& operator<<(std::ostream& lhs, ComplexNumbers& rhs)
{
	lhs << "Real: " << rhs.getReal() << " Imaginary: " << rhs.getImag();

	return lhs;
}