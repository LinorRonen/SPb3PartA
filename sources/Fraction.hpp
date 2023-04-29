#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <iostream>
#include <stdexcept>
using namespace std;

namespace ariel
{

class Fraction {

private:

    int numerator;

    int denominator;
    
    void reduce();
   
    int gcd(int num1, int num2);

public:

    // Default constructor
    Fraction(); 

    Fraction(int numerator, int denominator);
    //Fraction(int numerator);
    Fraction(float num);

    // copy constructor
    Fraction(const Fraction& other); 

    // Move constructor
    Fraction(Fraction&& other)noexcept;

    // Copy assignment operator
    Fraction& operator=(const Fraction& other);

    // Move assignment operator
    Fraction& operator=(Fraction&& other)noexcept;

    // Destructor
    ~Fraction();

    // Methods with Fractions
    // Arithmetic operations
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;
    // Comparison operations
    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    // Increment and decrement operations
    Fraction operator++(); // pre-increment
    Fraction operator++(int); // post-increment
    Fraction operator--(); // pre-decrement
    Fraction operator--(int); // post-decrement

    // Methods with float
    // Arithmetic operations
    const Fraction operator+(const float& num) const;
    const Fraction operator-(const float& num) const;
    const Fraction operator*(const float& num) const;
    const Fraction operator/(const float& num) const;
    //Comparison operations
    bool operator==(const float& other) const;
    bool operator!=(const float& other) const;
    bool operator>(const  float& other) const;
    bool operator<(const  float& other) const;
    bool operator>=(const float& other) const;
    bool operator<=(const float& other) const;

    // Getter and setter functions
    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int numerator);
    void setDenominator(int denominator);

    // Friend functions
    // Input and output operations
    friend std::ostream& operator<<(std::ostream& output, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& input, Fraction& fraction);
    //Arithmetic operations
    friend Fraction operator+(const float& num1, const Fraction& num2);
    friend Fraction operator-(const float& num1, const Fraction& num2);
    friend Fraction operator*(const float& num1, const Fraction& num2);
    friend Fraction operator/(const float& num1, const Fraction& num2);
    // Explicit conversion operators
    explicit operator float() const;
    explicit operator double() const;
};

}

#endif // FRACTION_HPP

