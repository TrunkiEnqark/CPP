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

int n, s, a[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> s;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int i = 1, j = 1, res = 0;
    long long sum = 0;
    while (j <= n) {
        sum += a[j];

        while (sum > s && i < j) {
            sum -= a[i];
            i++;
        }
        // sau while thi sum <= s => len = j - i + 1
        res = max(res, j - i + 1);


        j++;
    }
    cout << res;


    return 0;
}