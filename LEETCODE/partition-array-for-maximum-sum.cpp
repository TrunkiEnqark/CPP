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

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    deque<int> dq;
    vector<int> maxRange(n, 0);
    for (int i = 0; i < n; ++i) {
        while (!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();

        dq.push_back(i);

        if (dq.front() + k <= i) dq.pop_front();
        if (i >= k - 1) maxRange[i] = arr[dq.front()];
    }

    for (int i = k - 2; i >= 0; --i) maxRange[i] = maxRange[i + 1];

    int res = 0;
    for (int i = 0; i < n; ++i) {
        cout << maxRange[i] << ' ';
        res += maxRange[i];
    }
    return res;
}

void solve() {
    vector<int> x = {1,15,7,9,2,5,10};
    cout << maxSumAfterPartitioning(x, 3);
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