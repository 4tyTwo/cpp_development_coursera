#include <iostream>

using namespace std;

int main() {
    double total, threshold1, threshold2, sale1, sale2, price_coef;
    cin >>  total >> threshold1 >> threshold2 >> sale1 >> sale2;
    if (total > threshold1) {
        if (total > threshold2) {
            price_coef = (1 - sale2/100);
        }
        else {
            price_coef = (1 - sale1/100);
        }
    }
    else {
        price_coef = 1;
    }
    cout << total * price_coef;
    return 0;
}