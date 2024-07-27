#include <bits/stdc++.h>

using namespace std;

struct Point {
    int64_t x, y;

    Point() {}
    Point(int64_t _x, int64_t _y) : 
        x(_x), y(_y) {}

    Point operator + (const Point& o) {
        return Point(x + o.x, y + o.y);
    }

    bool operator == (const Point& o) {
        return (x == o.x && y == o.y);
    }
};

int64_t distance(Point a) {
    return (a.x * a.x + a.y * a.y);
}

int64_t distance(Point a, Point b) {
    return distance(Point(abs(a.x - b.x), abs(a.y - b.y)));
} 

int main() {
    Point A, B, C;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;

    if (A + B == C || A + C == B || B + C == A) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    // double AB = distance(A, B);
    // double AC = distance(A, C);
    // double BC = distance(B, C);
    // if (AB + AC > BC && AB + BC > AC && AC + BC > AB) {
    //     cout << "YES";
    // } else {
    //     cout << "NO";
    // }
}