#include <bits/stdc++.h>

#define NAME ""
#define repz(i, a) for (int i = 0; i < a; ++i)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = b; i >= a; --i)
#define ll long long
#define ld long double
#define ii pair<int, int>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        int cnt = 1;
        for (int j = 2; j <= m; ++j) {
            cnt *= n/i;
        }
        res += cnt;
    }    
    cout << res;

    return 0;
}