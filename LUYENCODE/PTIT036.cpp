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

int n, m, a[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);

    int X = 0;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int b;
        cin >> b;
        auto it = lower_bound(a, a + n, b);
        if (*it == b) X += (it - a + 1);
            else X--;   
    }
    if (X < 0) cout << 0;
        else cout << (1ll << (X%30));
    // cout << (ll) pow(2, 29);

    return 0;
}