#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.get();

    stringstream ss{};

    for (int i = 0; i < n; ++i) {
        map<string, set<string>> menu{};

        string str;
        getline(cin, str);

        ss.clear();
        ss.str(str);

        string name;
        ss >> name;

        string food;
        while (ss >> food) menu[food].insert(name);

        for (auto& [fd, people] : menu) {
            cout << fd;
            for (auto& p : people) cout << ' ' << p;
            cout << '\n';
        }
        cout << '\n';
    }

    return 0;
}