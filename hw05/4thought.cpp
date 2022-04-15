#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int MOD = 1e9 + 7;

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

void transfer(string& from, string& to) {
    to += from.back();
    from.pop_back();
}

string infixToPostfix(const string& infix) {
    string stk{}, result{};

    for (char c : infix) {
        if (isalnum(c)) result += c;
        else if (c == '(') stk.push_back(c);
        else if (c == ')') {
            while (stk.back() != '(') transfer(stk, result);
        }
        else {
            while (!stk.empty() && prec(c) <= prec(stk.back())) transfer(stk, result);
            stk.push_back(c);
        }
    }

    while (!stk.empty()) transfer(stk, result);

    return result;
}

int eval(const string& postfix) {
    vector<int> stk;
    for (char c : postfix) { // each of operands / operators is one character
        if (isdigit(c)) {
            stk.push_back(c - '0');
        }
        else {
            int x = stk.back();
            stk.pop_back();
            int y = stk.back();
            stk.pop_back();

            int ans{};
            switch (c) {
            case '+':
                stk.push_back(x + y);
                break;
            case '-':
                stk.push_back(y - x);
                break;
            case '*':
                stk.push_back(x * y);
                break;
            case '/':
                stk.push_back(y / x);
                break;
            }
        }
    }
    return stk.back();
}

int main() {

    string eq = "4 4 4 4";
    map<int, string> mp;

    for (auto i : "+-*/"s) {
        eq[1] = i;
        for (auto j : "+-*/"s) {
            eq[3] = j;
            for (auto k : "+-*/"s) {
                eq[5] = k;
                mp[eval(infixToPostfix(eq))] = eq;
            }
        }
    }

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        if (mp.find(x) != mp.end()) {
            for (char c : mp[x]) cout << c << ' ';
            cout << "= " << x << '\n';
        }
        else {
            cout << "no solution\n";
        }
    }

    return 0;
}