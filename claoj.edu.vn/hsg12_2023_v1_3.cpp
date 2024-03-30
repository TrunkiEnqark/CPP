#include <bits/stdc++.h>

#define NAME ""
#define repz(i, a) for (int i = 0; i < a; ++i)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = b; i >= a; --i)
#define ll long long
#define ld long double
#define ii pair<int, int>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

bool check(int n) {
    int cnt = 0;
    while (n != 1) {
        if (cnt == 10000) break;
        int sum = 0;
        for (int m = n; m > 0; m /= 10) {
            sum += (m%10) * (m%10);
        }
        n = sum;
        cnt++;
    }
    return n == 1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    for (int i = 1; i <= 100; ++i) {
        if (check(i)) cout << i << ' ';
    }

    return 0;
}