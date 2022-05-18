#include <iostream>
#ifndef ClASS_H
#define CLASS_H
template <typename T>
class Complex {

private: 
	T Real{};
	T Imaginary{};

public :
	Complex(T a, T b) :Real{ a }, Imaginary{ b }{};   // constructor
	Complex(const Complex& complex);   // copy constructor
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


#endif
