#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        for (int i = 0; i < s.size() - 1; i++) {
            if (roman[s[i]] < roman[s[i + 1]]) {
                res -= roman[s[i]];
            } else {
                res += roman[s[i]];
            }
        }
        return res + roman[s[s.size() - 1]];
    }

    string intToRoman(int num) {
        const vector<pair<int, string>> valueSymbols{
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"},
            {5, "V"}, {4, "IV"}, {1, "I"}};
        string res;
        for (const auto& [value, symbol] : valueSymbols) {
            while (num >= value) {
                res += symbol;
                num -= value;
            }
        }
        return res;
    }

    bool toolcheck(string s) {
        return s == intToRoman(romanToInt(s));
    }
};

int main() {
    string s;
    cout << "nhap so: ";
    cin >> s;

    Solution ch;
    if (ch.toolcheck(s)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}