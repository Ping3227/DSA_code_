#include <iostream>
#include <utility>
#ifndef ClASS_H
#define CLASS_H
template <typename T>
class Complex {
	template <typename T1>
	friend std::istream& operator>>(std::istream& stream, Complex<T1>& complex);
private: 
	T Real{};
	T Imaginary{};

public :
	Complex() = default; //default constructor
	Complex(T a, T b) :Real{ a }, Imaginary{ b }{};   // constructor
	//Complex(const Complex& complex);
	Complex(const Complex& complex);/// copy constructor
	Complex(Complex&& complex) noexcept ;  //move constructor
	~Complex() = default; // destructor
	Complex& operator=(const Complex& complex); //copy assignment
	Complex& operator=(Complex&& complex) noexcept;//move assignment
	
	
	// add
	
	Complex  operator+(const Complex& complex) const;
	Complex operator+(const T& number) const;
	//subtract
	
	Complex operator-(const Complex& complex)const;
	Complex operator-(const T& number) const;
	//multiple

	Complex operator*(const Complex& complex)const ;
	Complex operator*(const T& number)const;
	
	//divide
	Complex operator/(const Complex& complex)const;
	Complex operator/(const T& number) const;
	//equal 
	bool operator==(const Complex& complex) const {
		return Real == complex.Real &&
			Imaginary == complex.Imaginary;
	}
	bool operator==(const T& number) const{
		return Imaginary == 0 &&
			Real == number;
	}
	//not equal
	bool operator!=(const Complex& complex) const{
		return !((*this) == complex);
	}
	bool operator!=(const double& number) {
		return !((*this) == number);
	}


	void swap(Complex& complex) noexcept;

	double norm() const {
		return Real * Real - Imaginary * Imaginary;
	}

	Complex conjugate() const{
		Complex<T> conjugate{ *this };
		conjugate.Imaginary *= -1;
		return conjugate;
	}
	void showcomplex() {
		if (Imaginary > 0) {
			std::cout<< Real << '+' << Imaginary << 'i';
		}
		else {
			std::cout << Real << Imaginary << 'i';
		}
		std::cout << Real << '+' << Imaginary <<'i';
	}
	double GetReal()const {
		return Real;
	}
	double GetImaginary()const {
		return Imaginary;
	}
};
template <typename T>
Complex<T>::Complex(const Complex& complex)
	:Real{ complex.Real }, Imaginary{ complex.Imaginary } {}// copy constructor*/

template <typename T>
Complex<T>::Complex(Complex&& complex) noexcept
	:Real{ complex.Real }, Imaginary{ complex.Imaginary }{}//move constructor

template <typename T>
Complex<T>& Complex<T>::operator=(const Complex& complex) {
	Complex copy{ complex };
	swap(copy);
	return *this;
}//copy assignment

template <typename T>
Complex<T>& Complex<T>::operator=(Complex&& complex) noexcept {
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
	Complex copy{ *this };
	copy.Real = (Real * complex.Real) - (Imaginary * complex.Imaginary);
	copy.Imaginary = (Imaginary * complex.Real) + (Real * complex.Imaginary);
	return copy;
}

template <typename T>
Complex<T> Complex<T>::operator*(const T& number) const {
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
	copy = copy / ((complex.Real*complex.Real) - (complex.Imaginary*complex.Imaginary));
	return copy;
}

template <typename T>
Complex<T> Complex<T>::operator/(const T& number) const {
	Complex copy{ *this };
	copy.Real /= number;
	copy.Imaginary /= number;
	return copy;
}


template <typename T>
void Complex<T>::swap(Complex& complex) noexcept {
	std::swap(Real, complex.Real);
	std::swap(Imaginary, complex.Imaginary);
}


template <typename T>
inline std::ostream& operator<<(std::ostream& stream, const Complex<T>& complex) {
	if (complex.GetImaginary() >= 0) {
		stream << complex.GetReal() << '+' << complex.GetImaginary() << 'i';
	}
	else {
		stream << complex.GetReal()  << complex.GetImaginary() << 'i';
	}
	//inline because of link

	return stream;
}

template <typename T>
std::istream& operator>>(std::istream& stream,  Complex<T>& complex) {
	stream >> complex.Real >> complex.Imaginary;
	return stream;
}
#endif
