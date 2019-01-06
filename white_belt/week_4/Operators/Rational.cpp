#include <cmath>
#include <iostream>
#include <sstream>

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

istream& operator>> (istream& in, Rational& obj)
{
    if (in.tellg() == -1)
        return in;
    int numerator = 0, denominator = 1;
    in >> numerator;
    in.ignore(1);
    in >> denominator;
    obj = Rational(numerator, denominator);
    return in;
}

ostream& operator<< (ostream& out, const Rational& obj)
{
    out << obj.Numerator() << "/" << obj.Denominator();
    return out;
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
