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
const ll lim = 1e18;

int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int n;

void calc(int cnt, ll num, int k) {
    if (k > 16) return;
    if (cnt == n) {
        cout << num;
        exit(0);
    }
    for (int cntpk = 0; num <= lim && cnt + cntpk <= n; cntpk++) {
        num *= prime[k];
        calc(cnt + cntpk, num, k + 1);
    }
}

void solve() {
    cin >> n;
    calc(1, 1, 0);
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