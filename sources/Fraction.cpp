#include "Fraction.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;

namespace ariel
{

// Default constructor
Fraction::Fraction() : numerator(0), denominator(1) {}

//Constructor that gets numerator and denominator
Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator)
{
    if (denominator == 0)
    {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    reduce();
}

// Constructor that gets a float number
Fraction::Fraction(float f)
{
    int digits = 1000; // Maximum of three digits after the decimal point
    this->numerator = static_cast<int>(round(f * digits));
    this->denominator = digits;
    reduce();
}
	
// copy constructor
Fraction::Fraction(const Fraction& other) : numerator(other.numerator), denominator(other.denominator) {}

// Move constructor
Fraction::Fraction(Fraction&& other) noexcept : numerator(other.numerator), denominator(other.denominator)
{
    other.numerator = 0;
    other.denominator = 1;
}

// Copy assignment operator
Fraction& Fraction::operator=(const Fraction& other)
{
    if (this != &other) {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
    }
    return *this;
}

// Move assignment operator
Fraction& Fraction::operator=(Fraction&& other)noexcept
{
    if (this != &other) {
        
        this->numerator = other.numerator;
        this->denominator = other.denominator;

        other.numerator = 0;
        other.denominator = 1;
    }
    return *this;
}

// Destructor
Fraction::~Fraction(){}

void Fraction::reduce()
{
    if (denominator < 0)
    {
        this->numerator *= -1;
        this->denominator *= -1;
    }
    int div = gcd(abs(numerator), denominator);
    this->numerator /= div;
    this->denominator /= div;
}

int Fraction::gcd(int num1, int num2) 
{
    while (num2 != 0) 
    {
        int num3 = num2;
        num2 = num1 % num2;
        num1 = num3;
    }
    return num1;
}

// Arithmetic operations - Fraction
Fraction Fraction::operator+(const Fraction& other) const
{
    int theNumerator = this->numerator * other.denominator + other.numerator * this->denominator;
    int theDenominator = this->denominator * other.denominator;
    return Fraction(theNumerator,theDenominator);
}

Fraction Fraction::operator-(const Fraction& other) const
{
    int theNumerator = this->numerator * other.denominator - other.numerator * this->denominator;
    int theDenominator = this->denominator * other.denominator;
    return Fraction(theNumerator,theDenominator);
}

Fraction Fraction::operator*(const Fraction& other) const
{
    int theNumerator = this->numerator * other.numerator;
    int theDenominator= this->denominator * other.denominator;
    return Fraction(theNumerator,theDenominator);
}

Fraction Fraction::operator/(const Fraction& other) const
{
    if (other.numerator == 0) 
    {
        throw std::invalid_argument("Cannot divide by zero!");
    }
    int theNumerator = this->numerator * other.denominator;
    int theDenominator= this->denominator * other.numerator;
    return Fraction(theNumerator,theDenominator);
}

// Comparison operations
bool Fraction::operator==(const Fraction& other) const
{
    return ((this->numerator == other.numerator) && (this->denominator == other.denominator));
}

bool Fraction::operator!=(const Fraction& other) const
{
    return !(*this == other);
}

bool Fraction::operator>(const Fraction& other) const
{
    int num1 = this->numerator * other.denominator;
    int num2 = other.numerator * this->denominator;
    return num1 > num2;
}

bool Fraction::operator<(const Fraction& other) const
{
    int num1 = this->numerator * other.denominator;
    int num2 = other.numerator * this->denominator;
    return num1 < num2;
}

bool Fraction::operator>=(const Fraction& other) const
{
    return ( (*this > other) || (*this == other) );
}

bool Fraction::operator<=(const Fraction& other) const
{
    return ( (*this < other) || (*this == other) );
}

// Increment and decrement operations
Fraction Fraction::operator++()
{
    this->numerator += this->denominator;
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction beforeIncrement = *this;
    this->numerator += this->denominator;
    return beforeIncrement;
}

Fraction Fraction::operator--()
{
    this->numerator -= this->denominator;
    return *this;
}

Fraction Fraction::operator--(int)
{
    Fraction beforeDecrement = *this;
    this->numerator -= this->denominator;
    return beforeDecrement;
}


//--------------------------------------------------------------------

// Arithmetic operations - float number 
const Fraction Fraction::operator+(const float& numberF) const
{
    Fraction other(numberF);
    return (*this) + other;
}

const Fraction Fraction::operator-(const float& numberF) const
{
    Fraction other(numberF);
    return (*this) - other;
}

const Fraction Fraction::operator*(const float& numberF) const
{
    Fraction other(numberF);
    return (*this) * other;
}

const Fraction Fraction::operator/(const float& numberF) const
{
    Fraction other(numberF);
    return (*this) / other;
}

//Comparison operations
bool Fraction::operator==(const float& otherF) const {
    Fraction temp(otherF);
    return *this == temp;
}

bool Fraction::operator!=(const float& otherF) const {
    Fraction temp(otherF);
    return *this != temp;
}

bool Fraction::operator>(const float& otherF) const {
    Fraction temp(otherF);
    return *this > temp;
}

bool Fraction::operator<(const float& otherF) const {
    Fraction temp(otherF);
    return *this < temp;
}

bool Fraction::operator>=(const float& otherF) const {
    Fraction temp(otherF);
    return *this >= temp;
}

bool Fraction::operator<=(const float& otherF) const {
    Fraction temp(otherF);
    return *this <= temp;
}

//-------------------------------------------------------------------------------------

// Getter and setter functions
int Fraction::getNumerator() const 
{
    return this->numerator;
}

int Fraction::getDenominator() const 
{
    return this->denominator;
}

void Fraction::setNumerator(int numerator) 
{
    this->numerator = numerator;
}

void Fraction::setDenominator(int denominator) 
{
    this->denominator = denominator;
}

//---------------------------------------------------------------

// Friend functions

// Input and output operations
std::ostream& operator<<(std::ostream& output, const Fraction& fraction)
{
    output << fraction.numerator << "/" << fraction.denominator;
    return output;
}
std::istream& operator>>(std::istream& input, Fraction& fraction)
{
    int theNumerator,theDenominator;
    char slash;
    input >> theNumerator >> slash >> theDenominator;
    if (theDenominator == 0) 
    {
        throw std::invalid_argument(" The denominator cannot be zero!");
    }
    fraction = Fraction(theNumerator, theDenominator);
    return input;
}

Fraction operator+(const float& fNum, const Fraction& fraction)
{
    return Fraction(static_cast<int>(fNum * fraction.getDenominator()) + fraction.getNumerator(), fraction.getDenominator());
}

Fraction operator*(const float& fNum, const Fraction& fraction)
{
    return Fraction(static_cast<int>(fNum * fraction.getNumerator()), fraction.getDenominator());
}

Fraction operator-(const float& fNum, const Fraction& fraction) 
{
    float result = fNum - static_cast<float>(fraction);
    return Fraction(result);
}

Fraction operator/(const float& fNum, const Fraction& fraction)
{
    Fraction f_num(fNum);
    return f_num / fraction;
}
//-------------------------------------------------------------------------

// Explicit conversion operators
Fraction::operator float() const 
{
    return static_cast<float>(numerator) / static_cast<float>(denominator);
}
Fraction::operator double() const 
{
    return static_cast<double>(numerator) / static_cast<double>(denominator);
}
//--------------------------------
}
   
