#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cout << 1ll * i*i * (1ll*i*i - 1) / 2 - 4ll * (i - 1) * (i - 2) << endl; 
    }
}