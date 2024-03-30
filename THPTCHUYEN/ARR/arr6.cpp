#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(auto &it : a) cin >> it;
    
    int res = 0;
    for(int i = 0; i < n - 1; ++i)
        for(int j = i + 1; j < n; ++j)
            if (i < j && a[i] > a[j]) res++;
    cout << res;
}