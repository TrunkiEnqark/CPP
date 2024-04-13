#include <bits/stdc++.h>

#define NAME ""
#define repz(i, a) for (int i = 0; i < a; ++i)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = b; i >= a; --i)
#define ll long long
#define ld long double
#define ii pair<int, int>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

class TrieTree {
private:
    int Node[N][26], now = 0;
    bool isEnd[N];
    int cnt[N];
    // int health_value[N];
public:
    TrieTree() {
        memset(Node, -1, sizeof Node);
        memset(isEnd, false, sizeof isEnd);
        memset(cnt, 0, sizeof cnt);
    }

    void insert(string str) {
        int root = 1;
        for (int i = 0; i < str.size(); ++i) {
            int ch = str[i] - 'a';
            if (Node[root][ch] == -1) Node[root][ch] = ++now;
            root = Node[root][ch];
        }
        isEnd[root] = true;
        cnt[root]++;
    }

    int calculate(string str) {
        int root = 1;
        for (int i = 0; i < str.size(); ++i) {
            int ch = str[i] - 'a';
            if (Node[root][ch] == -1) return 0;
            root = Node[root][ch];
        }

        if (isEnd[root]) return cnt[root];
        return 0;
    }
};

int n;
pair<string, int> tmp[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> tmp[i].first;
    for (int i = 1; i <= n; ++i) cin >> tmp[i].second;

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        string str;
        cin >> str;
        TrieTree trie = TrieTree();
        trie.insert(str);

        ll res = 0;
        for (int i = l + 1; i <= r + 1; ++i) {
            int cnt = trie.calculate(tmp[i].first);
            res += 1ll * cnt * tmp[i].second;
        }

        cout << res << endl;
    }

    return 0;
}