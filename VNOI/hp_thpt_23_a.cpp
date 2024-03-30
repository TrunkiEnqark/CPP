#include <bits/stdc++.h>

using namespace std;

int divisor(int n) {
    int res = 0;
    for (int i = 1; i*i <= n; ++i) 
        if (n % i == 0) {
            if (n/i == i) res++;
                else res += 2; 
        }
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    cout << divisor(n);
}