#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n + 1], mink[n + 1];
    mink[0] = INT_MAX;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        mink[i] = min(mink[i - 1], a[i]);
    }

    int t;
    cin >> t;
    while(t--) {
        int k;
        cin >> k;
        cout << mink[k] << endl;
    }
}