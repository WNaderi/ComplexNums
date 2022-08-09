#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

class Complex
{
public:
    //Constructors
    Complex();
    Complex(double real);
    Complex(double real, double imaginary);

    // Member Functions
    Complex add(Complex other) const;
    Complex subtract(Complex other) const;
    Complex multiply(Complex other) const;
    Complex divide(Complex other) const;
    double abs() const;
    double getRealPart() const;
    double getImaginaryPart() const;
    string to_string() const;
    
    
    

    // operators
    Complex& operator+=(Complex other);
    double& operator[](int index);
    Complex operator-() const;
    Complex& operator++();
    Complex operator++(int x);
    Complex& operator--();
    Complex operator--(int x);
    Complex& operator*=(Complex other);
    Complex& operator/=(Complex other);

    // extraction and insertion
    friend std::istream& operator>>(std::istream& in, Complex& c);
    friend std::ostream& operator<<(std::ostream& out, const Complex& c);
    


private:
    double real; // The real number (A+bi).
    double imaginary; // The imaginary number (a+Bi).
};

//Constructors
Complex::Complex() {

    this->real = 0;
    this->imaginary = 0;

}

//Constructor beginning w/ only a real number.
Complex::Complex(double real) {

    this->real = real;

}


Complex::Complex(double real, double imaginary) {

    this->real = real;
    this->imaginary = imaginary;

}

//getters
//Returns the real number.
double Complex::getRealPart() const {

    return this->real;

}

//Returns the imaginary number.
double Complex::getImaginaryPart() const{

    return this->imaginary;

}

//Returns the Complex number as a string.
string Complex::to_string() const{

    std::ostringstream s;

    if (imaginary > 0.0) {

        s << real << " " << "+" << " " << imaginary << "i";

    } else if (imaginary < 0.0) {

        s << real << " " << " " << imaginary << "i";

    } else {

        s << real;

    }

    return s.str();

}

//Returns memory address of either real or imaginary number using array index.
double& Complex::operator[](int index) {

    if (index == 0) {

        return real;

    }

    if (index == 1) {

        return imaginary;
        
    }

    throw invalid_argument("Index out of range");

}

// non-members

//Adds two complex numbers.
Complex operator+(Complex left, Complex right)
{
    return left.add(right);
}

//Subtracts two complex numbers.
Complex operator-(Complex left, Complex right) {

    return left.subtract(right);

}

//Multiplies two complex numbers.
Complex operator*(Complex left, Complex right) {

    return left.multiply(right);

}

//Divides two complex numbers.
Complex operator/(Complex left, Complex right) {

    return left.divide(right);

}

// members of Complex

//Creates and returns a new complex number that has added this complex number with other complex number.
Complex Complex::add(Complex other) const
{
    return Complex(this->real + other.real, this->imaginary + other.imaginary);
}

//Creates and returns a new complex number that has subtracted this complex number with other complex number.
Complex Complex::subtract(Complex other) const {

    return Complex(this->real - other.real, this->imaginary - other.imaginary);

}

//Creates and returns a new complex number that has multiplied this complex number with other complex number.
Complex Complex::multiply(Complex other) const {

    double returnreal = (this->real * other.real) + -(this->imaginary * other.imaginary);
    double returnimag = (this->imaginary * other.real) + (this->real * other.imaginary);

    return Complex(returnreal, returnimag);

}

//Creates and returns a new complex number that has divided this complex number with other complex number.
Complex Complex::divide(Complex other) const {

    Complex conjugate(other.real, -(other.imaginary));
    
    Complex first = this->multiply(conjugate);
    Complex second = other.multiply(conjugate);

    return Complex(first.real / second.real, first.imaginary / second.real);
}

//Returns a new complex number that is negative.
Complex Complex::operator-() const {

    Complex temp(-(real), -(imaginary));

    return temp;

}

//Prefix increment of the real number in this complex number.
Complex& Complex::operator++() {

    real += 1.0;

    return *this;
}

//Postfix increment of the real number in this complex number.
Complex Complex::operator++(int x) {

    Complex other = *this;

    ++*this;

    return other;

}

//Prefix decrement of the real number in this complex number.
Complex& Complex::operator--() {

    real -= 1.0;

    return *this;
}

//Postfix decrement of the real number in this complex number.
Complex Complex::operator--(int x) {

    Complex other = *this;
    --*this;
    
    return *this;

}

//Adds the other complex number to this.
Complex& Complex::operator+=(Complex other) {

    this->real += other.real;
    this->imaginary += other.imaginary;

    return *this;
}

//Multiplies the other complex number by this.
Complex& Complex::operator*=(Complex other) {

    Complex temp = this->multiply(other);

    this->real = temp.real;
    this->imaginary = temp.imaginary;

    return *this;

}
//Divides the other complex number by this.
Complex& Complex::operator/=(Complex other) {

    Complex temp = this->divide(other);

    this->real = temp.real;
    this->imaginary = temp.imaginary;

    return *this;

}



//Returns absolute value of imaginary and real numbers added.
double Complex::abs() const {

    double sum = (this->real * this->real) + (this->imaginary * this->imaginary);
    return sqrt(sum);

}


// Insertion for real & imaginary numbers.
std::istream& operator>>(std::istream& in, Complex& c)
{

    in >> c.real;
    in >> c.imaginary;
    return in;
}

// Extraction of real & imaignary numbers.
ostream& operator<<(std::ostream& out, const Complex& c) {

    out << c.to_string();

    return out;
}

