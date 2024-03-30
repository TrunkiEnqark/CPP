#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

bool test(int k, int x, int a) {
    while(x--) {
        if (a <= 0) return false;
        int r = rand() % 2;
        if (r) {
            a += (k - 1) * a;    
        } else a--;
    }
    return true;
}

void solve() {
    int k, x, a;
    cin >> k >> x >> a;
    int t = 100, cnt = 0;
    while(t--) if (test(k, x, a)) cnt++;
    if (cnt >= 50) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int t = 1;
    cin >> t;
    while(t--) solve();
}