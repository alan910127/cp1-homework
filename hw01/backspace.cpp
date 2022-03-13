#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str{};
    getline(cin, str);

    string ans{};
    for (char c : str) {
        if (c == '<') {
            if (!ans.empty()) ans.pop_back();
        }
        else {
            ans += c;
        }
    }

    cout << ans << '\n';

    return 0;
}