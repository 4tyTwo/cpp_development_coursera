#include <cmath>
#include <iostream>

using namespace std;

class Rational {
public:
    Rational()
    {
        numerator = 0;
        denominator = 1;
    }
    Rational(int num, int denom)
    {
        if (num == 0) {
            numerator = num;
            denominator = 1;
            return;
        }
        int divisor = gcd(num, denom);
        num/=divisor;
        denom/=divisor;
        if (num < 0 && denom < 0) {
            num   = abs(num);
            denom = abs(denom);
        }
        else {
            if (denom < 0) {
                denom = abs(denom);
                num = - num;
            }
        }
        this->numerator = num;
        this->denominator = denom;
    }

    int Numerator() const
    {
        return numerator;
    }
    int Denominator() const
    {
        return denominator;
    }

private:
    int gcd(int a, int b) 
    {
        return b == 0 ? a : gcd(b, a % b);
    }
    int numerator, denominator;
};

Rational operator+ (const Rational& left, const Rational& right)
    {
        int new_num = left.Numerator() * right.Denominator() + right.Numerator() * left.Denominator();
        int new_denom = left.Denominator() * right.Denominator();
        return Rational(new_num, new_denom);
    }

Rational operator- (const Rational& left, const Rational& right)
    {
        int new_num = left.Numerator() * right.Denominator() - right.Numerator() * left.Denominator();
        int new_denom = left.Denominator() * right.Denominator();
        return Rational(new_num, new_denom);
    }

bool operator== (const Rational& left, const Rational& right)
    {
        return (left.Numerator() == right.Numerator() && left.Denominator() == right.Denominator());
    }

Rational operator* (const Rational& left, const Rational& right)
    {
        int new_num = left.Numerator() * right.Numerator();
        int new_denom = left.Denominator() * right.Denominator();
        return Rational(new_num, new_denom);
    }   

Rational operator/ (const Rational& left, const Rational& right)
    {
        int new_num = left.Numerator() * right.Denominator();
        int new_denom = left.Denominator() * right.Numerator();
        return Rational(new_num, new_denom);
    }   

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
