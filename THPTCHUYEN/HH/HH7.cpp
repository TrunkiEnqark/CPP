#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

struct Point {
    int x, y;
} points[N];

int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    long long area = 0;
    for (int i = 0; i <= n; ++i) {
        area += (points[i].y + points[(i + 1) % n].y) * (points[i].x - points[(i + 1) % n].x);
    }

    // sign = (x1 - x2) * (y1 + y2) + (x2 - x3) * (y2 + y3)

    if (area % 2 == 0) {
        cout << area / 2 << ' ' << 1;
    } else {
        cout << area << ' ' << 2;
    }

    return 0;
}