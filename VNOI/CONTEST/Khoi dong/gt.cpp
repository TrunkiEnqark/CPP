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

int main() {
    int n;
    cin >> n;

    int cnt5 = 0;
    for (int t = n, p = 5; t/p >= 1; p *= 5)
        cnt5 += t/p;

    int res = 1;
    for (int i = 2; i <= n; ++i) {
        int x = i;
        while (x%5 == 0) x /= 5;
        while (x%2 == 0 && cnt5 > 0) {
            x /= 2;
            cnt5--;
        }
        res = (res * x) % 10;
    }
    cout << res;

    return 0;
}