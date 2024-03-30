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
const int N = 1e6 + 5;

ll result[N];

void init() {
    result[1] = 1;
    for (int i = 2; i <= 1e6; ++i) result[i] = result[i - 1] + i;
    for (int i = 2; i <= 1e6; ++i) result[i] += result[i - 1];
}

void solve() {
    int n;
    cin >> n;
    cout << result[n] << '\n';
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);
    init();
    // for (int i = 1; i <= 20; ++i) cout << result[i] << endl;
    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}