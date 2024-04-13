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

void solve() {
    int n;
    cin >> n;
    vector<pair<pair<int, int>, vector<int>>> res;
    
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        vector<int> per;
        for (int j = 1; j <= n; ++j) per.push_back(j);
        if (i&1) reverse(per.begin(), per.end());
        sum += per[0];
        res.push_back({{1, i}, per});
    }

    for (int i = 1; i <= n; ++i) {
        vector<int> per;
        for (int j = 1; j <= n; ++j) per.push_back(j);
        if (i&1) reverse(per.begin(), per.end());
        // sum += per[0];
        res.push_back({{2, i}, per});
    }

    cout << sum << ' ' << 2*n << endl;
    for (auto it : res) {
        cout << it.first.first << ' ' << it.first.second << ' ';
        for (auto i : it.second) cout << i << ' ';
        cout << endl;
    }
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}