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

const int N = 1e7 + 5;
int n, k, cnt = 0;
bool sign[N];

void solve() {
    cin >> n >> k;
    memset(sign, true, sizeof sign);
    for (int i = 2; i <= n; ++i)
        if (sign[i]) {
            for (int j = i; j <= n; j += i)
                if (sign[j]) {
                    cnt++;
                    if (cnt == k) {
                        cout << j;
                        return;
                    }
                    sign[j] = false;
                }
        }
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