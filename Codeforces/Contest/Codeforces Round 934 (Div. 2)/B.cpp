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
const int N = 2e5 + 5;

int n;
ii cnt[N];

bool cmp(const ii &a, const ii &b) {
    return a.first < b.first;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cnt[i].first = 0, cnt[i].second = i;
    for (int i = 0; i < n; ++i) {
        int d;
        cin >> d;
        cnt[d].first++;
    } 
    for (int i = 0; i < n; ++i) {
        if (cnt[i].first == 0) cnt[i].first = 1e9;
    }
    sort (cnt, cnt + n);
    // for (int i = 0; i < n; ++i) cout << cnt[i].first << ' ';
    // cout << endl;
    vector<int> c;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        int v = cnt[i].first;
        // cout << v << ' ';
        if (v != 1e9 && v > k) {
            c.push_back(cnt[i].second);
            k++;
        }
    }

    sort(c.begin(), c.end());
    for (auto it : c) cout << it << ' ';
    cout << endl;
    for (int i = 0; i < n; ++i)
        if (!binary_search(c.begin(), c.end(), i)) {
            cout << i << endl;
            return;
        }
    cout << n << endl;
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}