#include <bits/stdc++.h>

using namespace std;

class BigNum {
private:
    vector<int> vec;
public:
    BigNum() {}

    BigNum(int sz) {
        vec.resize(sz, 0);
    }

    BigNum(string str) {
        vec.resize(str.size());
        for (int i = 0; i < vec.size(); ++i)
            vec[i] = str[i] - '0';
    }

    void fix_zeros() {
        while (!vec.empty() && *vec.begin() == 0) 
            vec.erase(vec.begin());
    }

    friend ostream& operator << (ostream&, const BigNum &obj) {
        for (int x : obj.vec) 
            cout << x;
        return cout;
    }

    friend istream& operator >> (istream& cin, BigNum &obj) {
        string str;
        cin >> str;
        obj = BigNum(str);
        return cin;
    }

    bool operator == (BigNum other) {
        this->fix_zeros();
        other.fix_zeros();
        if (vec.size() != other.vec.size()) return false;
        for (int i = 0; i < vec.size(); ++i) 
            if (vec[i] != other.vec[i]) return false;
        return true; 
    }

    BigNum operator + (BigNum other) {
        this->fix_zeros();
        other.fix_zeros();
        int result_len = max(vec.size(), other.vec.size());
        BigNum result(result_len);
        int i = 0, j = 0;
        while (i < vec.size() && j < other.vec.size()) {
            result.vec[i] = vec[i] + other.vec[j];
            i++, j++;
        }
        for (; i < vec.size(); ++i) result.vec[i] = vec[i];
        for (; j < other.vec.size(); ++j) result.vec[j] = other.vec[j]; 

        int cur = 0;
        for (int i = result_len - 1; i >= 0; --i) {
            result.vec[i] += cur;
            cur = result.vec[i] / 10;
            result.vec[i] %= 10;
        }
        if (cur > 0) result.vec.insert(result.vec.begin(), cur);
        return result;
    }
};

int main() {
    BigNum a = BigNum(1);
    BigNum b = BigNum(1);
    cin >> a >> b;
    cout << a + b;
    return 0;
}