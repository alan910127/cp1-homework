#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, t;
    cin >> n >> m >> t;

    vector<vector<pii>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].emplace_back(v, d);
        adj[v].emplace_back(u, d);
    }

    int source, target;
    cin >> source >> target;

    int numSpiders;
    cin >> numSpiders;

    priority_queue<pli, vector<pli>, greater<pli>> pq;
    for (int i = 0; i < numSpiders; ++i) {
        int pos;
        cin >> pos;
        pq.emplace(0, pos);
    }

    vector<ll> distToSpiders(n, LLONG_MAX >> 1);

    while (not pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();

        if (dist >= distToSpiders[u]) continue;
        distToSpiders[u] = dist;

        for (auto [v, w] : adj[u]) {
            if (dist + w >= distToSpiders[v]) continue;
            pq.emplace(dist + w, v);
        }
    }

    function<bool(int)> available = [&](int distance) -> bool {
        if (distToSpiders[source] < distance) return false;

        vector<ll> minDist(n, LLONG_MAX >> 1);
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        pq.emplace(0, source);

        while (not pq.empty()) {
            auto [dist, u] = pq.top();
            pq.pop();

            if (dist >= minDist[u]) continue;
            minDist[u] = dist;

            for (auto [v, w] : adj[u]) {
                if (dist + w >= minDist[v] or distToSpiders[v] < distance) continue;
                pq.emplace(dist + w, v);
            }
        }

        return minDist[target] <= t;
    };

    int ans = 0, step = (1 << 29);
    while (step > 0) {
        if (available(ans + step)) ans += step;
        step >>= 1;
    }

    cout << ans << '\n';

    return 0;
}