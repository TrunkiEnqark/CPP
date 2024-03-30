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

string ANS(int a, int b, int c) {
    if (a < b && b < c) return "STAIR";
    if (a < b && b > c) return "PEAK";
    return "NONE";
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> v = {a, b, c};
    sort(v.begin(), v.end());
    do {
        if (ANS(a, b, c) != "NONE") {
            cout << ANS(a, b, c) << '\n';
            return;
        }
    } while (next_permutation(v.begin(), v.end()));

    cout << "NONE\n";
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