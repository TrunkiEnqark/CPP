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
const int N = 1e4 + 5;

ll S[N + 1];

void init() {
    S[0] = 0;
    for (int i = 1; i <= N; ++i) {
        S[i] = S[i - 1] + 1ll*i*i*i;
    }
}

void solve() {
    int l, r;
    cin >> l >> r;
    cout << S[r] - S[l - 1] << '\n';
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    init();
    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}