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

class bignum {
private:
    vector<int> num;
public:
    bignum() {}
    bignum(vector<int> _num) : num(_num) {}

    bignum convert(int val) {
        bignum ans;
        for (; val; val /= 10) ans.num.push_back(val%10);
        reverse(ans.num.begin(), ans.num.end());
        return ans;
    }

    bignum multi(const bignum &o) {
        int n = num.size();
        int m = o.num.size();
        bignum ans(vector<int>(n+m-1, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans.num[i + j] += o.num[i] * num[j];
            }
        }

        int carry = 0;
        for (int i = n + m - 2; i >= 0; --i) {
            ans.num[i] += carry;
            carry = ans.num[i] / 10;
            ans.num[i] %= 10;
        }

        reverse(ans.num.begin(), ans.num.end());

        while(carry) {
            ans.num.push_back(carry%10);
            carry /= 10;
        }

        reverse(ans.num.begin(), ans.num.end());

        return ans;
    }

    void print() {
        for (int i = 0; i < num.size(); ++i) cout << num[i];
        cout << '\n';
    }
};

void solve() {
    int n;
    cin >> n;
    bignum res({1}), tmp;
    for (int i = 2; i <= n; ++i) {
        tmp = tmp.convert(i);
        res = res.multi(tmp);
    }
    res.print();
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