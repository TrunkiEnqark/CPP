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


int SumOfDivisors(int n) {
    int res = 0;
    for (int i = 2; i*i <= n; ++i) 
        if (n%i == 0) {
            if (n/i == i) res += i;
                else {
                    res += i;
                    res += n/i;
                }
        }
    return res + 1;
}

const int N = 5e5;
int SumDiv[N + 5];

void init() {
    memset(SumDiv, 0, sizeof SumDiv);
    for (int i = 1; i <= N; ++i) 
        for (int j = i*2; j <= N; j += i) SumDiv[j] += i;
}

void solve() {
    init();
    int l, r;
    cin >> l >> r;
    int res = 0;
    for (int i = l; i <= r; ++i) {
        if (SumDiv[i] > i) res++;
    }
    cout << res;
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