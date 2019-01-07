#include <cmath>
#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <stdexcept>

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
        if (denom == 0)
            throw invalid_argument("Invalid argument");
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
        if (right.Numerator() == 0)
            throw domain_error("Division by zero");
        int new_num = left.Numerator() * right.Denominator();
        int new_denom = left.Denominator() * right.Numerator();
        return Rational(new_num, new_denom);
    }   


istream& operator>> (istream& in, Rational& obj)
{
    if (!in) {
        return in;
    }
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

bool operator< (const Rational& left, const Rational& right)
{
    return (left.Numerator() + .0)/left.Denominator() < (right.Numerator() + .0)/right.Denominator();
}


int main() {
    Rational a, b;
    char oper;
    try {
        cin >> a >> oper >> b;
    }
    catch (invalid_argument& e) {
        cout << e.what() << endl;
        return 0;
    }
    switch (oper) {
        case '+' : 
            cout << a + b << endl;
            break;
        case '-' : 
            cout << a - b << endl;
            break;
        case '*' : 
            cout << a * b << endl;
            break;
        case '/' : 
            try {
                cout << a / b << endl;
            }
            catch (domain_error& e) {
                cout << e.what() << endl;
            }
            break;
    }
    return 0;
}
