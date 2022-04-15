#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

bool available(int temperature) {
    static const pii position[]{
        /*  for 0 */ pii{ 3, 1 },
        pii{ 0, 0 }, pii{ 0, 1 }, pii{ 0, 2 },
        pii{ 1, 0 }, pii{ 1, 1 }, pii{ 1, 2 },
        pii{ 2, 0 }, pii{ 2, 1 }, pii{ 2, 2 }
    };

    vector<int> press;
    for (; temperature > 0; temperature /= 10) {
        press.push_back(temperature % 10);
    }

    for (int i = press.size() - 1; i > 0; --i) {
        auto [x1, y1] = position[press[i]];
        auto [x2, y2] = position[press[i - 1]];
        if (x1 > x2 or y1 > y2) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int nCases;
    cin >> nCases;

    while (nCases--) {
        int temperature;
        cin >> temperature;

        if (available(temperature)) {
            cout << temperature << '\n';
            continue;
        }

        for (int i = 1;; ++i) {
            if (available(temperature + i)) {
                cout << temperature + i << '\n';
                break;
            }
            if (available(temperature - i)) {
                cout << temperature - i << '\n';
                break;
            }
        }
    }

    return 0;
}