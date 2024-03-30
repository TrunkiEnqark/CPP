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

string s[2] = {"##", ".."};

void solve() {
    int n;
    cin >> n;
    string res;
    int c1 = 0, c2 = 1;
    for (int i = 1; i <= n; ++i) {
        string tmp;
        for (int i = 1; i <= n; ++i) tmp += s[c1], c1 = (c1 + 1) % 2;
        res += tmp + "\n" + tmp + "\n"; 
        if (n%2 == 0) c1 = (c1 + 1) % 2;
    }
    cout<< res;
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