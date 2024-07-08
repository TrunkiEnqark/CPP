#include <bits/stdc++.h>

#define NAME "cau5"
#define repz(i, a) for (int i = 0; i < a; ++i)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = b; i >= a; --i)
#define ll long long
#define ld long double
#define ii pair<int, int>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 5e3 + 5;

int n, arr[N];
map<int, int> cnt;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> arr[i], arr[i] *= arr[i], cnt[arr[i]]++;

    sort (arr + 1, arr + n + 1);

    int nhon = 0, vuong = 0, tu = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int it1 = lower_bound(arr + 1, arr + n + 1, arr[i] + arr[j]) - (arr + 1) - 1;
            int it2 = upper_bound(arr + 1, arr + n + 1, arr[i] + arr[j]) - (arr + 1);
            cout << it1 << " " << it2 << endl;
            nhon += it1;
            tu += it2;
            vuong += cnt[arr[i] + arr[j]];
        }
    }
    cout << nhon << ' ' << vuong << ' ' << tu;

    return 0;
}