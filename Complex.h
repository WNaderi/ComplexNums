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
    double real;
    double imaginary;
};

//Constructors

Complex::Complex() {

    this->real = 0;
    this->imaginary = 0;

}

Complex::Complex(double real) {

    this->real = real;

}

Complex::Complex(double real, double imaginary) {

    this->real = real;
    this->imaginary = imaginary;

}

//getters
double Complex::getRealPart() const {

    return this->real;

}

double Complex::getImaginaryPart() const{

    return this->imaginary;

}


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
Complex operator+(Complex left, Complex right)
{
    return left.add(right);
}

Complex operator-(Complex left, Complex right) {

    return left.subtract(right);

}

Complex operator*(Complex left, Complex right) {

    return left.multiply(right);

}

Complex operator/(Complex left, Complex right) {

    return left.divide(right);

}

// members of Complex
Complex Complex::add(Complex other) const
{
    return Complex(this->real + other.real, this->imaginary + other.imaginary);
}

Complex Complex::subtract(Complex other) const {

    return Complex(this->real - other.real, this->imaginary - other.imaginary);

}

Complex Complex::multiply(Complex other) const {

    double returnreal = (this->real * other.real) + -(this->imaginary * other.imaginary);
    double returnimag = (this->imaginary * other.real) + (this->real * other.imaginary);

    return Complex(returnreal, returnimag);

}

Complex Complex::divide(Complex other) const {

    Complex conjugate(other.real, -(other.imaginary));
    
    Complex first = this->multiply(conjugate);
    Complex second = other.multiply(conjugate);

    return Complex(first.real / second.real, first.imaginary / second.real);
}

Complex Complex::operator-() const {

    Complex temp(-(real), -(imaginary));

    return temp;

}

Complex& Complex::operator++() {

    real += 1.0;

    return *this;
}

Complex Complex::operator++(int x) {

    Complex other = *this;

    ++*this;

    return other;

}

Complex& Complex::operator--() {

    real -= 1.0;

    return *this;
}

Complex Complex::operator--(int x) {

    Complex other = *this;
    --*this;
    
    return *this;

}

Complex& Complex::operator+=(Complex other) {

    this->real += other.real;
    this->imaginary += other.imaginary;

    return *this;
}

Complex& Complex::operator*=(Complex other) {

    Complex temp = this->multiply(other);

    this->real = temp.real;
    this->imaginary = temp.imaginary;

    return *this;

}

Complex& Complex::operator/=(Complex other) {

    Complex temp = this->divide(other);

    this->real = temp.real;
    this->imaginary = temp.imaginary;

    return *this;

}




double Complex::abs() const {

    double sum = (this->real * this->real) + (this->imaginary * this->imaginary);
    return sqrt(sum);

}


// Operators (for cin/cout)
std::istream& operator>>(std::istream& in, Complex& c)
{

    in >> c.real;
    in >> c.imaginary;
    return in;
}

ostream& operator<<(std::ostream& out, const Complex& c) {

    out << c.to_string();

    return out;
}

