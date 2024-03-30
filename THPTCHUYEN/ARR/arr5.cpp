#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(auto &it : a) cin >> it;
    
    int res = 0;
    for(auto it : a) 
        if(500 <= it && it <= 3000) res++;
    cout << res;
}