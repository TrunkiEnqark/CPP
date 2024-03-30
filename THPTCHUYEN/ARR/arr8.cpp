#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], cnt[101];
    memset(cnt, 0, sizeof cnt);
    for(auto &it : a) {
        cin >> it;
        cnt[it]++;
    }
    
    cout << *max_element(cnt, cnt+101);
}