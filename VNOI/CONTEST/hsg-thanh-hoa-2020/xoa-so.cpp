#include <bits/stdc++.h>

#define NAME "CAU3"
#define repz(i, a) for (int i = 0; i < a; ++i)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = b; i >= a; --i)
#define ll long long
#define ld long double
#define ii pair<int, int>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

int pre[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    string str;
    cin >> str;
    int n = str.size();
    str = "#" + str;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + str[i] - '0';
        sum += str[i] - '0';
    }
    
    int cnt[5];
    memset(cnt, 0, sizeof cnt);
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        int tmp = sum - pre[i];
        res += cnt[tmp % 3];
        res += cnt[3 - tmp%3];
        cnt[pre[i] % 3]++;
    }
    cout << res + (sum % 3 == 0);

    return 0;
}