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

    sort (points, points + n, 
        [] (const Point& a, const Point& b) {
            return (a.x < b.x || (a.x == b.x && a.y < b.y));
    });

    for (int i = 0; i < n; ++i) {
        cout << points[i].x << " " << points[i].y << endl;
    }

    return 0;
}