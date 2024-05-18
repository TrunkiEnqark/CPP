#include <bits/stdc++.h>

using namespace std;

const char last_digit_perfect_square[] = {'0', '1', '4', '5', '6', '9'};
const bool is_square[] = {1, 1, 0, 0, 1, 0, 0, 0, 0, 1};

int calc_sum(string str) {
    int res = 0;
    do {
        res = 0;
        for (auto ch : str) res += ch - '0';
        str = to_string(res);
    } while (str.size() > 1);
    return res;
}

int main() {
    string str;
    cin >> str;

    int sum = calc_sum(str);
    if (!(sum == 1 || sum == 4 || sum == 7 || sum == 9)) {
        cout << 0;
        return 0;
    }

    char last_digit = str.back();
    // cout << last_digit << endl;
    char second_last_digit = (str.size() >= 2 ? str[str.size() - 2] : '0');
    char third_last_digit = (str.size() >= 3 ? str[str.size() - 3] : '0');
    int number = (third_last_digit - '0') * 10 + (second_last_digit - '0');
    int count_zeros = 0;
    for (int i = str.size() - 1; i >= 0 && str[i] == '0'; count_zeros++, i--) {}
    switch (last_digit) {
        case '0': {
            if (second_last_digit == '0' && count_zeros % 2 == 0) {
                cout << 1;
                return 0;
            }
        }
        case '1': {
            if ((second_last_digit - '0') % 2 == 0) {
                cout << 1;
                return 0;
            }
        }
        case '4': {
            if ((second_last_digit - '0') % 2 == 0) {
                cout << 1;
                return 0;
            }
        }
        case '9': {
            if ((second_last_digit - '0') % 2 == 0) {
                cout << 1;
                return 0;
            }
        }
        case '5': {
            if (second_last_digit == '2') {
                cout << 1;
                return 0;
            }
        }
        case '6': {
            if ((second_last_digit - '0') % 2 != 0) {
                cout << 1;
                return 0;
            }
        }
    }

    cout << 0;

    return 0;
}