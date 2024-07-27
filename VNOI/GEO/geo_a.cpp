#include <bits/stdc++.h>

using namespace std;

const long double PI = 3.14159265358979323846;

int main() {
    long double x, y;
    cin >> x >> y;
    // long double r = sqrt(x * x + y * y);
    if (y >= 0)
        cout << fixed << setprecision(10) << acosl((long double) 1.0 * x / sqrtl(x*x + y*y));
    else 
        cout << fixed << setprecision(10) << - acosl((long double) 1.0 * x / sqrtl(x*x + y*y)) + 2 * PI;
}