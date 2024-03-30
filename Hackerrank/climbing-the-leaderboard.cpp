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
const int N = 2e5 + 5;

int n, m;
vector<int> ranked, player;

void solve() {
    cin >> n;
    ranked.resize(n);
    for (auto &i : ranked) cin >> i;
    cin >> m;
    player.resize(m);
    for (auto &i : player) cin >> i;

    reverse(ranked.begin(), ranked.end());
    ranked.resize(distance(ranked.begin(), unique(ranked.begin(), ranked.end())));
    n = ranked.size();
    // for (auto it : ranked) cout << it << ' ';
    // cout << endl;
    vector<int> result;
    for (int i : player) {
        // cout << upper_bound(ranked.begin(), ranked.end(), i) - ranked.begin() - 1 << endl;
        result.push_back(n - (upper_bound(ranked.begin(), ranked.end(), i) - ranked.begin()) + 1);
    }
    for (auto i : result) cout << i << '\n';
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