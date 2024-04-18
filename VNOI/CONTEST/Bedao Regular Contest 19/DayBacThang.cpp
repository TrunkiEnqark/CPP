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

int n, a[N], dp[N], trace[N];
vector<int> pos[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }

    memset(trace, -1, sizeof trace);

    for (int i = 1; i <= n; ++i) {
        for (int j : pos[a[i] - 1]) {
            if (j > i && dp[j] < dp[i] + 1) {
                dp[j] = dp[i] + 1;
                trace[j] = i;
            } 
        }
    }

    int min_pos = max_element(dp + 1, dp + n + 1) - dp;
    cout << dp[min_pos] + 1 << endl;
    vector<int> res;
    int i;
    for (i = min_pos; trace[i] != -1; i = trace[i]) 
        res.push_back(i);   
    res.push_back(i);
    reverse(res.begin(), res.end());
    for (auto it : res) cout << it << ' ';
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}