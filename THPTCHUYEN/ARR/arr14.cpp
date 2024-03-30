#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, a[N];

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    long long sum = 0;
    for(int i = 1; i < n; ++i) sum += a[i];
    if(sum == (long long) a[n]) cout << sum;
        else cout << 'N';
}