#include <bits/stdc++.h>

#define NAME ""
#define repz(i, a) for (int i = 0; i < a; ++i)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = b; i >= a; --i)
#define ll long long
#define ld long double
#define ii pair<int, int>

using namespace std;

vector<int> primes;

void eratosthenes(int lim = 1e3 + 5) {
    bool is_prime[lim + 1];
    memset(is_prime, true, sizeof(is_prime));    
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i*i <= lim; ++i) {
        if (is_prime[i])
            for (int j = i*i; j <= lim; j += i)
                is_prime[j] = false; 
    }

    for (int i = 2; i <= lim; ++i)
        if (is_prime[i]) primes.push_back(i);
}

int legendre(int n, int p) {
    int res = 0;
    for (int i = p; i <= n; i *= p)
        res += n/i;
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    eratosthenes();
    int n;
    while (cin >> n) {
        for (int i = 0; primes[i] <= n; i++)
            cout << legendre(n, primes[i]);
        cout << endl;
    }

    return 0;
}