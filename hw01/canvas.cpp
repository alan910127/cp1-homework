#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i{}; i < n; ++i) {
        int s;
        cin >> s;
        pq.push(s);
    }

    ll ans{};
    while (pq.size() > 1) {
        ll x{ pq.top() };
        pq.pop();
        ll y{ pq.top() };
        pq.pop();

        ans += x + y;
        pq.emplace(x + y);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}