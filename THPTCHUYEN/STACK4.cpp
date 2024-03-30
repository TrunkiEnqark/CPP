#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n[3], a[3][N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n[0] >> n[1] >> n[2];
    for(int k = 0; k < 3; ++k) {
        for(int i = n[k]; i > 0; --i) cin >> a[k][i];
        for(int i = 1; i <= n[k]; ++i) a[k][i] += a[k][i - 1];
    }

    for(int i = max({n[0], n[1], n[2]}); i > 0; --i) {
        int f1 = a[0][i];
        int f2 = *lower_bound(a[1] + 1, a[1] + n[1] + 1, a[0][i]);
        int f3 = *lower_bound(a[2] + 1, a[2] + n[2] + 1, a[0][i]);
        if(f1 == f2 && f1 == f3) {
            cout << f1;
            return 0;
        }
    }
}