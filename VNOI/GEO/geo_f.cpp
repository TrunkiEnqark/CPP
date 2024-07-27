#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

int main() {
    ld x, y, xB, yB, xC, yC;
    cin >> x >> y;
    cin >> xB >> yB >> xC >> yC;

    ld xN = (yC - yB) * (-1);
    ld yN = (xC - xB);

    ld A = xN;
    ld B = yN;
    ld C = - xN * xB - yN * yB;

    cout << fixed << setprecision(10) << 1.0l * abs(A * x + B * y + C) / sqrtl(A*A + B*B);
}