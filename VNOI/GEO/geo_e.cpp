#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

int main() {
    ld x, y, A, B, C;
    cin >> x >> y;
    cin >> A >> B >> C;

    cout << fixed << setprecision(10) << 1.0l * abs(A * x + B * y + C) / sqrtl(A*A + B*B);
}