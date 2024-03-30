#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;

int n, a[N], maxR[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    maxR[n] = a[n];
    for (int i = n - 1; i >= 1; --i) maxR[i] = max(maxR[i + 1], a[i]);

    long long res = 0;

    for (int i = 1; i <= n - 2; ++i)
        for (int j = i + 1; j <= n - 1; ++j)
            if (maxR[j + 1] > a[j] && a[j] > a[i])
                res = max(res, (long long) a[i] + a[j] + maxR[j + 1]);

    cout << (res == 0 ? -1 : res);

    return 0;
}