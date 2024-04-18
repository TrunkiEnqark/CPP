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

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll a, b;
    cin >> a >> b;
    ll current = a/b;
    cout << current << '.';
    a -= current * b;
    if (a == 0) {
        cout << 0;
        return 0;
    }
 //   vector<ll> rotation;
    vector<ll> vec;
    map<ll, int> sign;
    bool ok = false;
    int X = 1;
    sign[a] = X++;
    // cout << a << endl;
    while (a != 0) {
        if (a < b) a *= 10;
        current = a/b;
        a -= current * b;
        vec.push_back(current);
        // cout << a << endl;
        if (sign.count(a)) {
            X = sign[a] - 1;
            ok = true;
            break;
        }

        sign[a] = X++;
    }

    bool p = ok;
    // cout << X << endl;
    for (int i = 0; i < vec.size(); ++i) {
        if (ok && p && i == X) {
            cout << "(" << vec[i];
            p = false;
        } else {
            cout << vec[i];
        }
    }
    if (ok) cout << ")";

    return 0;
}