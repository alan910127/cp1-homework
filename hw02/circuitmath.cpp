#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<bool> var(n);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        var[i] = (c == 'T');
    }

    char c;
    vector<bool> stack{};
    while (cin >> c) {
        if (isalpha(c)) {
            stack.push_back(var[c - 'A']);
        }
        else {
            if (c == '-') {
                stack.back().flip();
                continue;
            }

            bool x{ stack.back() };
            stack.pop_back();
            bool y{ stack.back() };
            stack.pop_back();

            if (c == '+') {
                stack.push_back(x || y);
            }
            else {
                stack.push_back(x && y);
            }
        }
    }

    cout << (stack.back() ? 'T' : 'F') << '\n';

    return 0;
}