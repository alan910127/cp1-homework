#include <bits/stdc++.h>
using namespace std;

struct Client {
    int money;
    int time;

    Client() = default;
    Client(int monet, int time) : money{ money }, time{ time } {}

    bool operator>(const Client& rhs) const {
        return money > rhs.money;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    vector<Client> clients(n);
    for (auto& c : clients) {
        cin >> c.money >> c.time;
    }

    sort(clients.begin(), clients.end(), greater<Client>{});

    set<int> timeAvailable;
    for (int i{}; i < n; ++i) {
        timeAvailable.emplace_hint(timeAvailable.end(), i);
    }

    int ans{};
    for (auto& c : clients) {
        if (*timeAvailable.begin() <= c.time) {
            if (auto it{ prev(timeAvailable.upper_bound(c.time)) }; it != timeAvailable.end()) {
                timeAvailable.erase(it);
                if (*it < t) ans += t;
            }
            else {
                timeAvailable.erase(prev(timeAvailable.end()));
            }
        }
    }

    cout << ans << '\n';

    return 0;
}