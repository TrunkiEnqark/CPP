#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(auto &it : a) cin >> it;
    
    int res = INT_MAX;
    for(auto it : a) 
        if(it % 2) res = min(res, it);
    cout << res;
}