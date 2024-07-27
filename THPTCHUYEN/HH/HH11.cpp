#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int X1, X2, X3, Y1, Y2, Y3;

int main() {
    cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3; 
    long long sign = (X2 - X1) * (Y3 - Y1) + (X3 - X1) * (Y1 - Y2);
    if (sign == 0) cout << "0";
    else if (sign > 0) cout << 1;
    else cout << -1;

    return 0;
}