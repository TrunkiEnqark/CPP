#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;
map<ll, ll> F;

ll fib(ll n) {
    if (F.count(n)) return F[n];

    ll k = n/2;
    if (n%2 == 0) {
        return F[n] = (fib(k) * fib(k) + fib(k - 1) * fib(k - 1)) % MOD;
    }
    return F[n] = (fib(k) * fib(k - 1) + fib(k) * fib(k + 1)) % MOD;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    F[0] = F[1] = 1;
    while(t--) {
        ll n;
        cin >> n;
        cout << (n == 0 ? 0 : fib(n - 1)) << '\n';
    }
}

/*
    F(2k + 1) = F(k) * F(k) + F(k - 1) * F(k - 1)
    F(2k) = F(k) * [F(k - 1) + F(k + 1)] 
          = F(k) * F(k - 1) + F(k) * F(k + 1)
    https://en.wikipedia.org/wiki/Fibonacci_sequence#Matrix_form
    https://codeforces.com/blog/entry/14516
*/