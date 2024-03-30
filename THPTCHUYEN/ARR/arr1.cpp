#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(auto &it : a) cin >> it;
    cout << *min_element(a, a+n);
}