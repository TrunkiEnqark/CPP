#include <bits/stdc++.h>

using namespace std;

struct Point {
    long double x, y;

    Point() {}
    // Point(int _x, int _y) : x(_x), y(_y) {}

    long double distance() {
        return sqrtl(x*x + y*y);
    }
};

long long dot_product(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

int main() {
    Point a, b;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    // cout << a.distance() << endl;
    // cout << dot_product(a, b) / (a.distance() * b.distance()) << endl;
    cout << fixed << setprecision(10) << acosl(dot_product(a, b) / (a.distance() * b.distance()));
}