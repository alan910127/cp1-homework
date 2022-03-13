#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.get();

    string str;
    getline(cin, str);

    vector<char> stack{};
    for (int i = 0; i < n; ++i) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            stack.push_back(str[i]);
            continue;
        }

        if (str[i] == ')') {
            if (stack.empty() || stack.back() != '(') {
                cout << str[i] << ' ' << i << '\n';
                exit(EXIT_SUCCESS);
            }
            stack.pop_back();
        }
        else if (str[i] == ']') {
            if (stack.empty() || stack.back() != '[') {
                cout << str[i] << ' ' << i << '\n';
                exit(EXIT_SUCCESS);
            }
            stack.pop_back();
        }
        else if (str[i] == '}') {
            if (stack.empty() || stack.back() != '{') {
                cout << str[i] << ' ' << i << '\n';
                exit(EXIT_SUCCESS);
            }
            stack.pop_back();
        }
    }

    cout << "ok so far\n";

    return 0;
}