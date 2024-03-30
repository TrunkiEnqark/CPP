#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n, a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int leftValue = a[1], rightValue = a[n];
    int lenLeft = 0, lenRight = 0;
    for (int i = 1; i <= n && a[i] == leftValue; i++, lenLeft++) {}
    for (int i = n; i >= 1 && a[i] == rightValue; i--, lenRight++) {}

    if (lenLeft == n || lenRight == n) {
        cout << 0 << endl;
        return;
    }

    if (lenRight > lenLeft) swap(lenLeft, lenRight);
    if (a[1] == a[n]) lenLeft += lenRight, lenRight = 0;
    cout << n - lenLeft << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int t = 1;
    cin >> t;
    while(t--) solve();
}