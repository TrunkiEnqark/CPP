#include <bits/stdc++.h>

#define NAME ""

#define fo(i, a, b) for(int i = a; i <= b; ++i)
#define all(a)		a.begin(), a.end()

#define pb 			push_back
#define endl		'\n'
#define ll 			long long
#define ii 			pair<int, int>
#define fi 			first
#define se 			second

using namespace std;

const int N = 5e3 + 5;

int n, a[N];

int get(int i, int j) {
    return a[j] - a[i - 1];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], a[i] += a[i - 1];

    int res = 0;
    for(int k = 2; k <= n; ++k) {
        int i = 1, j = n;
        while(get(i, k) != get(k + 1, j) && i <= k && j > k) {
            if(get(i, k) > get(k + 1, j)) ++i; else --j;
        }
        if(i <= k && j > k) {
            cout << i << ' ' << j << endl;
            res = max(res, j - i + 1);
        }
    }
    cout << res;

    return 0;
}

//http://thptchuyen.ntucoder.net/Problem/Details/6866