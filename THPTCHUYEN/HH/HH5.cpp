#include <bits/stdc++.h>

using namespace std;

int64_t a, b, c, xA, xB, yA, yB;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> a >> b >> c >> xA >> yA >> xB >> yB;
    int64_t result_a = a*xA + b*yA + c;
    int64_t result_b = a*xB + b*yB + c;

    if (result_a * result_b > 0) {
        cout << 1;
    } else if (result_a * result_b < 0) {
        cout << -1;
    } else {
        cout << 0;
    }

    return 0;
}