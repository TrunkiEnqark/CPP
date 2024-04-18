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
const int N = 4e7;

ll x[N + 5], a, b, c;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b >> c;
    x[0] = 1;
    for (int i = 1; i <= N; ++i) {
        x[i] = (ll) (a * x[i - 1] + x[i - 1] / b) % c;
    }
    // for (int i = 1; i <= 100; ++i) cout << x[i] << ' ';
    // cout << endl;
    int Tortoise = 1, Hare = 1;

    while (true) {
        Tortoise++;
        Hare += 2;
        if (x[Tortoise] == x[Hare]) break;
    }

    int lamda = 0, mul = 0;
    Hare = 1;
    while (x[Hare] != x[Tortoise]) {
        mul++;
        Tortoise++;
        Hare++;
    }
    // cout << Hare << ' ' << Tortoise << endl;
    while (true) {
        lamda++;
        Hare++;
        if (x[Hare] == x[Tortoise]) break;
    }
    if (lamda > 0 && mul > 0) mul++;
    cout << lamda + mul;

    return 0;
}