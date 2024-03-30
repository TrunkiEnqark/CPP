#include <bits/stdc++.h>

#define NAME ""
#define repz(i, a) for (int i = 0; i < a; ++i)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = b; i >= a; --i)
#define ll long long
#define ld long double
#define ii pair<int, int>

using namespace std;

const int MOD = 1337377;
const int N = 3e5 + 5;
const int maxTrie = 5e6 + 5;

class Trie {
public:
    int trie[maxTrie][26], cnt;
    bool isEnd[maxTrie];

    Trie() {
        memset(trie, -1, sizeof trie);
        memset(isEnd, false, sizeof isEnd);
        cnt = 0;
    }

    void add(string s) {
        int root = 0;
        for (int i = 0; i < s.size(); ++i) {
            int nxt = s[i] - 'a';
            if (trie[root][nxt] == -1) trie[root][nxt] = ++cnt;
            root = trie[root][nxt];
        }
        isEnd[root] = true;
    }
};

Trie tree = Trie();
string s;
int n, dp[N];

void solve() {
    cin >> s;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string tmp;
        cin >> tmp;
        tree.add(tmp);
    }
    dp[0] = 1;
    for (int i = 0; i < s.size(); ++i) {
        int u = 0;
        for (int j = i; j < s.size(); ++j) {
            int nxt = s[j] - 'a';
            if (tree.trie[u][nxt] == -1) break;
            u = tree.trie[u][nxt];
            if (tree.isEnd[u]) dp[j + 1] = (dp[j + 1] + dp[i]) % MOD;
        }
    }
    cout << dp[s.size()];
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}
