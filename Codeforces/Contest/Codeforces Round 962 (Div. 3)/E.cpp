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

void solve() {
    map<int, ll> cnt;
    ll result = 0;
    int pre_sum = 0;
    string s;
    cin >> s;
    cnt[0] = 1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') {
            pre_sum++;
        } else {
            pre_sum--;
        }

        result += 1ll * cnt[pre_sum] * (s.size() - i);
        result %= MOD;
        cnt[pre_sum] += (i + 2);
    }
    cout << result << '\n';
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