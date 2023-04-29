#include "doctest.h"
#include <cstring>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include "sources/Fraction.hpp"
using namespace std;
using namespace ariel;


TEST_CASE("Test1: Creating a fraction.")
{
    
    CHECK_NOTHROW(Fraction());  

    CHECK_NOTHROW(Fraction (3, 1));

    CHECK_NOTHROW(Fraction (1, 3));
    
    CHECK_NOTHROW(Fraction (100, 100));

    CHECK_NOTHROW(Fraction (6));

    CHECK_NOTHROW(Fraction (-3, 4));

    CHECK_NOTHROW(Fraction (3, -4));

    CHECK_NOTHROW(Fraction (-3, -3));

    CHECK_THROWS(Fraction (4, 0));

}


TEST_CASE("Test2: Check the reduction action.")
{
    
    Fraction f1(5,10);

    CHECK((double)f1==0.5);

    Fraction f2(-5,-10);

    CHECK((double)f2==0.5);

    Fraction f3(5,-10);

    CHECK((double)f3==-0.5);

    Fraction f4(-5,10);
    
    CHECK((double)f4==-0.5); 
}



TEST_CASE("Test3: Adding fractions.")
{
    Fraction f1(1, 2);

    Fraction f2(1, 3);

    Fraction f3(5, 6);

    Fraction f4 = f1 + f2;

    Fraction f5 = f1 + f3;

    CHECK(f4 == Fraction(5, 6));

    CHECK(f5 == Fraction(4, 3));

    Fraction f6(-0.25);

    Fraction f7(0.25);

    Fraction f8 = f6+f7;
    CHECK(f8 == Fraction(0));
}

TEST_CASE("Test4: Subtracting fractions.")
{
    Fraction f1(3, 4);

    Fraction f2(1, 4);

    Fraction f3 = f1 - f2;

    CHECK(f3 == Fraction(1, 2));

    Fraction f4(1, 1);

    Fraction f5(1, 1);

    Fraction f6 = f4 - f5;

    CHECK(f6 == Fraction(0));
}

TEST_CASE("Test5: Multiplying fractions.")
{
    Fraction f1(1, 3);

    Fraction f2(3, 4);

    Fraction f3 = f1 * f2;

    CHECK(f3 == Fraction(1, 4));
}

TEST_CASE("Test6: Dividing fractions.")
{
    Fraction f1(1, 2);

    Fraction f2(3, 4);

    Fraction f3 = f1 / f2;

    CHECK(f3 == Fraction(2, 3));

    Fraction f4 = f1/ f1;

    CHECK(f4 == Fraction(1));

    CHECK_THROWS(f1 / Fraction(0, 1));
}

TEST_CASE("Test7: Comparing fractions.")
{
    Fraction f1(3, 4);

    Fraction f2(1, 2);

    Fraction f3(6, 8);

    Fraction f4(7, 8);

    CHECK(f1 > f2);

    CHECK(f2 < f1);

    CHECK(f1 >= f3);

    CHECK(f1 <= f4);

    CHECK(f1 != f2);

    CHECK(f1 == f3);
}

TEST_CASE("Test8: Incrementing and decrementing fractions.")
{
    Fraction f1(3, 4);

    Fraction f2(1, 4);

    ++f1;
    --f2;

    CHECK(f1 == Fraction(7, 4));

    CHECK(f2 == Fraction(-3, 4)); 

    f1++;
    f2--;

    CHECK(f1 == Fraction(11, 4));

    CHECK(f2 == Fraction(-7, 4)); 
}


TEST_CASE("Test9: Printing...")
{
    Fraction f1(3, 4);

    Fraction f2(1, 2);

    CHECK_NOTHROW(cout<< f1 << endl);

    CHECK_NOTHROW(cout<< f2 << endl);

    CHECK_NOTHROW(cout<< f1+f2 << endl);

    CHECK_NOTHROW(cout<< f1-f2 << endl);

    CHECK_NOTHROW(cout<< f1*f2 << endl);

    CHECK_NOTHROW(cout<< f1/f2 << endl);

    CHECK_NOTHROW(cout<< (f1+0.25) << endl);

    CHECK_NOTHROW(cout<< (f2+0.5) << endl);

    CHECK_NOTHROW(cout<< f1++ << endl);

    CHECK_NOTHROW(cout<< ++f1 << endl);

    CHECK_NOTHROW(cout<< f1-- << endl);

    CHECK_NOTHROW(cout<< --f1 << endl);

    Fraction f3(7.456);
    CHECK(f3 == Fraction(7456, 1000));
    CHECK_NOTHROW(cout<< f3 << endl);
    CHECK_NOTHROW(cout<< f3*1.0 << endl);
    CHECK_NOTHROW(cout<< f3*1<< endl);

    Fraction f4(0.2);
    CHECK_NOTHROW(cout<< f4*0.25 << endl);

    CHECK_NOTHROW(cout << boolalpha << (f1 >= f2) << endl);

    Fraction f5(1);
    Fraction f6= f4+f5-1;
    CHECK(f6 == f4);
    CHECK_NOTHROW(cout<< f6*1.00000f << endl);
    CHECK_NOTHROW(cout<< f6*1 << endl);
}
