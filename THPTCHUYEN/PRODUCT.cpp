#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 1e5 + 5;

int m, n;
ll k, a[N], b[N];
map<ll, int> cnt;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    ll res = 0;
    for(int j = 1; j <= m; ++j) {
        cin >> b[j];
        if(b[j] == 0 && k == 0) res += n; 
        if(b[j] != 0 && k%b[j] == 0) res += cnt[k / b[j]];
    } 
    cout << res;
}