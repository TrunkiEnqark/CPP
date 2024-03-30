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

int n, m;
ii a[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i].first, a[i].second = i + 1;
    sort(a, a + n);
    for (int i = 0; i < m; ++i) {
        int b;
        cin >> b;
        auto it = lower_bound(a, a + n, make_pair(b, 0));
        if (it->first == b) cout << it->second << ' ';
            else cout << 0 << ' ';
    }

    return 0;
}