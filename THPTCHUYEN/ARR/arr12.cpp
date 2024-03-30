#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, a[N];

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) {
        if(a[i]%2 == 0) a[i] /= 2;
            else a[i]++; 
    }
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; ++i) cout << a[i] << ' ';
}