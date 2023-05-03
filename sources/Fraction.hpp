#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <iostream>
#include <stdexcept>
using namespace std;

namespace ariel
{

class Fraction {

private:

    int numerator; // the numerator of the fraction

    int denominator; // the denominator of the fraction
    
    void reduce(); // reduce() method - in order to reduce the fraction
   
    int gcd(int num1, int num2); // gcd() method- in order to find a maximum common denominator

public:

    // Default constructor
    Fraction(); 

     // Constructor that get numerator and denominator
    Fraction(int numerator, int denominator);

    // Constructor that get float num
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

    // Arithmetic operations (get Fractions)
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    // Comparison operations(get Fractions)
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

    // Arithmetic operations(get float num)
    const Fraction operator+(const float& numF) const;
    const Fraction operator-(const float& numF) const;
    const Fraction operator*(const float& numF) const;
    const Fraction operator/(const float& numF) const;

    //Comparison operations(get float num)
    bool operator==(const float& otherF) const;
    bool operator!=(const float& otherF) const;
    bool operator>(const  float& otherF) const;
    bool operator<(const  float& otherF) const;
    bool operator>=(const float& otherF) const;
    bool operator<=(const float& otherF) const;

    // Getter and setter functions
    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int numerator);
    void setDenominator(int denominator);

    // Input and output operations - friend functions
    friend std::ostream& operator<<(std::ostream& output, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& input, Fraction& fraction);
    
    //Arithmetic operations - friend functions
    friend Fraction operator+(const float& numF, const Fraction& fraction);
    friend Fraction operator-(const float& numF, const Fraction& fraction);
    friend Fraction operator*(const float& numF, const Fraction& fraction);
    friend Fraction operator/(const float& numF, const Fraction& fraction);

    // Explicit conversion operators
    explicit operator float() const;
    explicit operator double() const;
};

}

#endif // FRACTION_HPP

