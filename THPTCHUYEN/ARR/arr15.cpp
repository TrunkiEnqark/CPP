#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, a[N];

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int result = INT_MIN;
    for(int i = 1; i <= n; ++i) 
        if(a[i] < 0) result = max(result, a[i]);
    if(result == INT_MIN) cout << "NOSOL";
        else cout << result;
}