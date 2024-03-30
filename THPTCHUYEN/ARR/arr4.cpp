#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(auto &it : a) cin >> it;
    
    int res = 0;
    for(auto it : a) res += abs(it);
    cout << res;
}