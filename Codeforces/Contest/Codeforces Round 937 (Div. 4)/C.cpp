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
    string s;
    cin >> s;
    int h = stoi(s.substr(0, 2));
    string m = s.substr(3, 2);
    string type = "AM";
    if (h == 12) type = "PM";
    if (h == 0) h = 12;
    if (h > 12) h -= 12, type = "PM";
    string res = to_string(h) + ":" + m + " " + type + "\n";
    if (res.size() == 8) res = "0" + res;
    cout << res;
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