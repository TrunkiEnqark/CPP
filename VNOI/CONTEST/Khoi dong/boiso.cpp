#include <bits/stdc++.h>

using namespace std;

bool check(unsigned long long n) {
    for (; n; n /= 10) 
        if (n%10 != 0 && n%10 != 1) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    unsigned long long n;
    cin >> n;
    unsigned long long res = n;
    for (unsigned long long i = 1; !check(res); i++) res += n;
    cout << res;
    return 0;
}