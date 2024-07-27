#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

const long double PI = 3.14159265358979323846;

ld distance(ld x, ld y) {
    return sqrtl(1.0l * x*x + 1.0l * y*y);
}

int main() {
    ld xA, yA, xB, yB, xC, yC;
    cin >> xA >> yA;
    cin >> xB >> yB >> xC >> yC;

    ld xU = xC - xB;
    ld yU = yC - yB;

    ld t = - ((xB - xA) * xU + (yB - yA) * yU) / ((xC - xB) * xU + (yC - yB) * yU);

    ld xH = xB + xU * t;
    ld yH = yB + yU * t;

    ld BH = distance(xH - xB, yH - yB);
    ld BC = distance(xC - xB, yC - yB);
    ld HC = distance(xC - xH, yC - yH);

    ld xN = (yC - yB) * (-1);
    ld yN = (xC - xB);

    ld A = xN;
    ld B = yN;
    ld C = - xN * xB - yN * yB;

    if (t > 1e-9l) {
        cout << fixed << setprecision(10) << 1.0l * abs(A * xA + B * yA + C) / sqrtl(A*A + B*B);
    } else {
        cout << fixed << setprecision(10) << sqrtl((xA - xB) * (xA - xB) + (yA - yB) * (yA - yB));
    }
}