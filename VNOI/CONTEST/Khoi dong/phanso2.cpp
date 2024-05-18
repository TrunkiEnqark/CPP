#include <bits/stdc++.h>

using namespace std;

template <typename T> T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

template <typename T> T lcm(T a, T b) {
    T _gcd = gcd(a, b);
    return (a / _gcd) * b;
}

long long make_nine(int len) {
    long long res = 0;
    while (len--) {
        res = res*10 + 9;
    }
    return res;
}

class Fraction {
private:
    /*
        numberator
        -----------
        denominator
    */
    long long numberator;
    long long denominator;
public:
    Fraction() {}
    Fraction(long long a = 1, long long b = 1) : numberator(a), denominator(b) {}

    Fraction compact() {
        int flag = (numberator < 0 ? -1 : 1);
        long long g = gcd(flag * numberator, denominator);
        return Fraction(numberator / g, denominator / g);
    }

    Fraction operator + (Fraction other) {
        long long temp = lcm(denominator, other.denominator);
        return Fraction(numberator * (temp / denominator) + other.numberator * (temp / other.denominator), temp).compact();
    }

    Fraction operator - (Fraction other) {
        long long temp = lcm(denominator, other.denominator);
        return Fraction(numberator * (temp / denominator) - other.numberator * (temp / other.denominator), temp).compact();
    }

    Fraction operator * (Fraction other) {
        return Fraction(numberator * other.numberator, denominator * other.denominator).compact();
    }

    friend ostream& operator << (ostream&, const Fraction& obj) {
        cout << obj.numberator << '/' << obj.denominator;
        return cout;
    }

    friend istream& operator >> (istream& cin, Fraction& obj) {
        cin >> obj.numberator >> obj.denominator;
        return cin;
    }
};

class DecimalNumber {
private:
    long long digit;
    string ths;
    string repeating;
    // digit.ths(repeating)
public:
    DecimalNumber() {}
    DecimalNumber(long long a = 0, string b = "0", string c = "0") : digit(a), ths(b), repeating(c) {}
    DecimalNumber(string str) {
        int pos = str.find('.');
        if (pos == -1) {
            digit = stoll(str);
            ths = "0";
            repeating = "0";
        } else {
            digit = stoll(str.substr(0, pos));
            str.erase(0, pos + 1);
            if (str[0] == '(') str = "0" + str;
            pos = str.find('(');
            if (pos == -1) {
                ths = str;
                repeating = "0";
            } else {
                ths = str.substr(0, pos);
                str.erase(0, pos + 1);
                repeating = str.substr(0, str.size() - 1);
            }
        }
    }

    Fraction ths_to_fraction() {
        return Fraction(stoll(ths), pow(10, ths.size())).compact();
    }

    Fraction repeating_to_fration() {
        Fraction compensation(1, pow(10, ths.size()));
        if (ths == "0") compensation = Fraction(1, 1);
        return (compensation * Fraction(stoll(repeating), make_nine(repeating.size()))).compact();
    }

    Fraction decimal_to_fraction() {
        return (Fraction(digit, 1) + this->ths_to_fraction() + this->repeating_to_fration()).compact();
    }

    friend istream& operator >> (istream& cin, DecimalNumber &obj) {
        string str;
        cin >> str;
        obj = DecimalNumber(str);
        return cin;
    }

    friend ostream& operator << (ostream&, const DecimalNumber &obj) {
        cout << obj.digit;
        if (obj.ths != "0") cout << "." << obj.ths;
        if (obj.repeating != "0") cout << "(" << obj.repeating << ")";
        return cout;
    }
};

int main() {    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    DecimalNumber data("0.00");
    cin >> data;
    cout << data.decimal_to_fraction();
    return 0;
}