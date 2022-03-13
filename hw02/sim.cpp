#include <bits/stdc++.h>
using namespace std;

void solve() {
    string str;
    getline(cin, str);

    list<char> lst{};
    auto pos{ lst.end() };
    for (char c : str) {
        if (c == '<') {
            if (pos == lst.begin()) continue;
            pos = lst.erase(prev(pos));
        }
        else if (c == '[') {
            pos = lst.begin();
        }
        else if (c == ']') {
            pos = lst.end();
        }
        else {
            pos = next(lst.insert(pos, c));
        }
    }

    cout << string(lst.begin(), lst.end()) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.get();
    while (t--) {
        solve();
    }

    return 0;
}