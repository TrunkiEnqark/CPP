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

string morganAndString(string a, string b) {
    a += 'z';
    b += 'z';
    string result;
    int i = 0, j = 0;
    while (a != "z" || b != "z") {
        if (a < b) result += a[0], a.erase(a.begin());
            else result += b[0], b.erase(b.begin());
    }
    // while (i < a.size()) result += a[i++];
    // while (j < b.size()) result += b[j++];
    return result;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("morgan-and-a-string.inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        cout << morganAndString(a, b) << '\n';
    }

    return 0;
}
