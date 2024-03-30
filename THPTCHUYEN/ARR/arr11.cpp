#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, a[N];

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    if(n%2 == 0) {
        int sum = a[n/2] + a[n/2 + 1];
        cout << sum / 2;
        if(sum%2) cout << ".5";
    } else {
        cout << a[(n + 1)/2];
    }
}   