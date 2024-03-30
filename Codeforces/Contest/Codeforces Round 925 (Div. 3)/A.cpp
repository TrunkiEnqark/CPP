#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
    int s;
    cin >> s;
    for (char c1 = 'a'; c1 <= 'z'; ++c1)
        for (char c2 = 'a'; c2 <= 'z'; ++c2)
            for (char c3 = 'a'; c3 <= 'z'; ++c3) {
                if (c1 + c2 + c3 + 3 - 'a' * 3 == s) {
                    cout << c1 << c2 << c3 << endl;
                    return;
                }
            }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int t = 1;
    cin >> t;
    while(t--) solve();
}