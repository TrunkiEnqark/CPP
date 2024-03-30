#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
const int lim = 1e6 + 6;

long long F[lim], subF[lim + 5];
int sign[lim + 5];
bool isPrime[lim + 5];

void sieve() {
    memset(isPrime, true, sizeof isPrime);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i*i <= lim; ++i) {
        if (isPrime[i])
            for (int j = i*i; j <= lim; j += i) isPrime[j] = false;
    }
}

void initialization() {
    memset(F, 0, sizeof F);
    memset(subF, 0, sizeof subF);
    int k = 0;
    for (int i = 2; i <= lim; ++i) {
        F[i] = F[i - 1];
        subF[i] = subF[i - 1];
        if (isPrime[i]) {
            (subF[i] += i) %= MOD;
            sign[i] = k++;
            (F[i] += 1ll*k*i) %= MOD;
        }
    }
}

long long getsum(long long arr[], int l, int r) {
    return (arr[r] - arr[l - 1]) % MOD;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    sieve();
    initialization();
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        int k = l;
        while (!isPrime[k]) k++;
        cout << (getsum(F, l, r) - sign[k] * getsum(subF, l, r) + MOD*MOD) % MOD << '\n';
    }
    return 0;
}