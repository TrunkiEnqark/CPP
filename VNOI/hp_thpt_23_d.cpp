#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        mp[a[i]]++;
    }

    if (k%2 == 0) {
        cout << 0;
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (mp.count(k - a[i])) { cout << 1; return; }
    }

    cout << 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) solve();
}