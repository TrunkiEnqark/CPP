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
const int N = 4e5 + 5;

int s[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        s[i] = ch - '0';
    }   
    for (int i = 1; i < n; ++i) s[i] += s[i - 1];

    int curry = 0;
    string res;
    for (int i = n - 1; i >= 0; --i) {
        curry += s[i];
        res.push_back(char(curry%10 + '0'));
        curry /= 10;
    } 

    while (curry > 0) {
        res.push_back(char(curry%10 + '0'));
        curry /= 10;
    }
    reverse (res.begin(), res.end());
    while (!res.empty() && res[0] == '0') res.erase(res.begin());
    cout << res << '\n';
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