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

bool check(string s, int len) {
    string tmp = s.substr(0, len);
    int n = s.size() / len;
    string str;
    for (int _ = 0; _ < n; ++_) str += tmp;
    int cnt = 0;
    // cout << str << ' ' << s << endl;
    for (int i = 0; i < str.size(); ++i) {
        // if (cnt > 1) return false;
        cnt += (str[i] != s[i]);
    } 
    // cout << cnt << ' ' << n << endl;
    return (cnt <= 1 || cnt == n - 1);
}

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int res = n, l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(s, mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << n << endl;
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    freopen(NAME".out", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}