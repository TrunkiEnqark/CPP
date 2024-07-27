#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct Point {
    int x, y;

    Point() {}
    // Point(long double x, long double y) : x(x), y(y) {}

    long double distance() {
        return sqrtl(x*x + y*y);
    }
};

int n;
Point points[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    long long area = 0;
    for (int i = 0; i < n; ++i) {
        area += 1ll * (points[i].x - points[(i + 1) % n].x) * (points[i].y + points[(i + 1) % n].y);
    }
    
    if (area % 2 == 0) {
        cout << area / 2 << ".000";
    } else {
        cout << area / 2 << ".500";
    }
}