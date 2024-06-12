#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int n;
int stones[N][3];
int dp[N];
int trace[N];

// i < j
bool check(pair<int, int> i, pair<int, int> j) {
    return i.first <= j.first && i.second <= j.second;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) cin >> stones[i][j];
        sort(stones[i], stones[i] + 3, greater<int>());
        dp[i] = stones[i][2];
    }
    cout << "--------------\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) 
            cout << stones[i][j] << ' ';
        cout << endl;
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) 
            cout << dp[j] << " \n"[j == n];
        int j_max = 0;
        for (int j = 1; j <= n; ++j) {
            if (i != j)
                if (check({stones[i][0], stones[i][1]}, {stones[j][0], stones[j][1]}) && dp[j_max] < dp[j]) {
                    j_max = j;
                    // trace[i] = j;
                }
        }
        dp[i] += dp[j_max];
        trace[i] = j_max;
    }

    for (int i = 1; i <= n; ++i) 
        cout << dp[i] << ' ';

    return 0;
}