#include <bits/stdc++.h>

#define ld long double
#define ll long long

using namespace std;

const int N = 1e5 + 5;

struct Point {
    ll x, y;

    Point() {}
    Point(ll x, ll y) : x(x), y(y) {}

    ld distance() {
        return sqrtl(x*x + y*y);
    }
};

struct Equation {
    ll a, b, c;

    Equation() {}
    Equation(ll _a, ll _b, ll _c) : 
        a(_a), b(_b), c(_c) {}
    
    Equation(Point A, Point B) {
        Point u(B.x - A.x, B.y - A.y);
        Point n(u.y * (-1), u.x);
        
        a = n.x;
        b = n.y;
        c = -n.x * A.x - n.y * A.y;

        ll g = __gcd<ll>(a, __gcd<ll>(b, c));
        a /= g;
        b /= g;
        c /= g;
    }
};

int main() {
    Point X, Y, Z;
    cin >> X.x >> X.y;
    cin >> Y.x >> Y.y;
    cin >> Z.x >> Z.y;

    Equation XY(X, Y);
    Equation XZ(X, Z);

    // optimize(XY, XZ);

    ld t1 = sqrtl(1.0l * XY.a * XY.a + 1.0l * XY.b * XY.b);
    ld t2 = sqrtl(1.0l * XZ.a * XZ.a + 1.0l * XZ.b * XZ.b);

    ld res[3];

    res[0] = (1.0l * XY.a / t1 - 1.0l * XZ.a / t2);
    res[1] = (1.0l * XY.b / t1 - 1.0l * XZ.b / t2);
    res[2] = (1.0l * XY.c / t1 - 1.0l * XZ.c / t2);

    cout << fixed << setprecision(10) << res[0] << ' ' << res[1] << ' ' << res[2]; 
}