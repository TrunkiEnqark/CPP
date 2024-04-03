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
const int N = 1e6 + 5;

int n, k, a[N], l[N], r[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    deque<int> dq;
    dq.push_back(0);
    for (int i = 1; i <= n; ++i) {
        while (!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
        l[i] = dq.back() + 1;
        dq.push_back(i);
    }
    dq.clear();
    dq.push_back(n + 1);
    for (int i = n; i >= 1; --i) {
        while (!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
        r[i] = dq.back() - 1;
        dq.push_back(i);
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        // cout << l[i] << ' ' << r[i] << endl;
        int len = r[i] - l[i] + 1;
        if (len < a[i]) continue;
        res = max(res, min(a[i], len));
    }
    cout << res;
    // cout << *max_element(dp + 1, dp + n + 1);

    return 0;
}