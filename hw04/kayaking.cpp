#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

bool tryArrange(int numPeople[3], int first, int second) {
    --numPeople[first];
    --numPeople[second];

    if (numPeople[first] < 0 or numPeople[second] < 0) {
        ++numPeople[first];
        ++numPeople[second];
        return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int b, n, e;
    cin >> b >> n >> e;

    int m{ (b + n + e) / 2 };

    int sb, sn, se;
    cin >> sb >> sn >> se;

    pii combination[]{
        pii{ sb + sb, 11 }, pii{ sb + sn, 12 }, pii{ sb + se, 13 },
        pii{ sn + sn, 22 }, pii{ sn + se, 23 }, pii{ se + se, 33 }
    };
    sort(begin(combination), end(combination));

    vector<int> factor(m);
    for (int& c : factor) cin >> c;
    sort(factor.begin(), factor.end(), greater<int>{});

    function<bool(int)> available = [&](int slowest) -> bool {
        int numPeople[3]{ b, n, e };

        for (auto c : factor) {
            bool flag = true;
            for (auto [speed, comb] : combination) {
                if (c * speed >= slowest) {
                    int first{ (comb / 10) - 1 };
                    int second{ (comb % 10) - 1 };
                    if (tryArrange(numPeople, first, second)) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) return false;
        }
        return true;
    };

    int ans = 0, step = 1 << 27; // step ~ 200'000'000 / 2
    while (step > 0) {
        if (available(ans + step)) ans += step;
        step >>= 1;
    }

    cout << ans << '\n';

    return 0;
}