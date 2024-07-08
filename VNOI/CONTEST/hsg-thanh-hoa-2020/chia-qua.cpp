#include <bits/stdc++.h>

#define NAME "CAU1"
#define repz(i, a) for (int i = 0; i < a; ++i)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = b; i >= a; --i)
#define ll long long
#define ld long double
#define ii pair<int, int>

using namespace std;

bool check(int x, int y, int i) {
    int tmp = x / i;
    return (y % tmp == 0);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen(NAME".inp", "r", stdin);
    freopen(NAME".out", "w", stdout);

    int x, y;
    cin >> x >> y;

    if (x > y) swap(x, y);
    int res = 0;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            if (x / i == i) {
                res += check(x, y, i);
            } else {
                res += check(x, y, i);
                res += check(x, y, x/i);
            }
        }
    }
    cout << res;

    return 0;
}