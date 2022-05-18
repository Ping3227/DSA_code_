#include "class.h"
#include <utility>

template <typename T>
Complex<T>::Complex(const Complex<T>& complex) 
	:Real{ complex.Real }, Imaginary{complex.Imaginary } {}// copy constructor

template <typename T>
Complex<T>::Complex(Complex<T>&& complex) noexcept
	:Real{ complex.Real }, Imaginary{ complex.Imaginary }{}//move constructor

template <typename T>
Complex<T>& Complex<T>::operator=(const Complex& complex) {
	Complex copy{ complex };
	swap(copy);
	return *this;
}//copy assignment

template <typename T>
Complex<T>& Complex<T>::operator=(Complex&& complex) noexcept{
	Complex moved{ std::move(complex) };
	swap(moved);
	return *this;
}//move assignment

template <typename T>
Complex<T> Complex<T>::operator+(const Complex& complex) const {
	Complex copy{ *this };
	copy.Real += complex.Real;
	copy.Imaginary += complex.Imaginary;
	return copy;
}

template <typename T>
Complex<T> Complex<T>::operator+(const T& number) const {
	Complex copy{ *this };
	copy.Real += number;
	return copy;
}

//subtract
template <typename T>
Complex<T> Complex<T>::operator-(const Complex& complex)const {
	Complex copy{ *this };
	copy.Real -= complex.Real;
	copy.Imaginary -= complex.Imaginary;
	return copy;

}

template <typename T>
Complex<T> Complex<T>::operator-(const T& number) const {
	Complex copy{ *this };
	copy.Real -= number;
	return copy;
}

//multiple
template <typename T>
Complex<T> Complex<T>::operator*(const Complex& complex) const {
	Complex copy{*this};
	copy.Real = (Real * complex.Real) - (Imaginary * complex.Imaginary);
	copy.Imaginary = (Imaginary * complex.Real) + (Real * complex.Imaginary);
	return copy;
}

template <typename T>
Complex<T> Complex<T>::operator*(const T& number) const{
	Complex copy{ *this };
	copy.Real *= number;
	copy.Imaginary *= number;
	return copy;
}

//divide
template <typename T>
Complex<T> Complex<T>::operator/(const Complex& complex) const {
	Complex copy{ *this };
	copy = copy * complex.conjugate();
	copy = copy/ ((complex.Real*complex.Real) - (complex.Imaginary*complex.Imaginary));
	return copy;
}

template <typename T>
Complex<T> Complex<T>::operator/(const T& number) const {
	Complex copy{ *this };
	copy.Real/= number;
	copy.Imaginary /= number;
	return copy;
}


template <typename T>
void Complex<T>::swap(Complex& complex) noexcept {
	std::swap(Real, complex.Real);
	std::swap(Imaginary, complex.Imaginary);
}
