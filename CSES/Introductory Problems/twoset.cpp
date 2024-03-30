#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int n, sign[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    long long target = 1ll * n * (n + 1) / 2;

    if (target % 2) { cout << "NO"; return 0; }

    target /= 2;

    long long sum = 0;
    int cnt0 = 0, cnt1 = 0;
    memset(sign, 0, sizeof sign);
    for (int i = 1; i <= n; ++i) {
        sum += i;
        sign[i] = 1;
        cnt1++;
        if (sum >= target) {
            if (sum > target) {
                sign[sum - target] = 0;
                cnt1--;
            }
            break;
        }
    }   
    cout << "YES\n";
    cnt0 = n - cnt1;
    cout << cnt1 << endl;
    for (int i = 1; i <= n; ++i)
        if (sign[i]) cout << i << ' ';
    cout << endl << cnt0 << endl;
    for (int i = 1; i <= n; ++i)
        if (!sign[i]) cout << i << ' ';
    
    return 0;
}