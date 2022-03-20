#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(2 * n);
    // i in [0, n) : forced adj list of i
    // i in [n, 2n) : adj list of (i - n)

    for (int u = 0; u < n; ++u) {
        adj[n + u].push_back(u);
    }

    for (int i{}; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --v;

        if (u < 0) {
            u = -u - 1;
            adj[n + u].push_back(n + v);
            adj[u].push_back(v);
        }
        else {
            --u;
            adj[n + u].push_back(v);
        }
    }

    deque<int> q{ n };
    vector<bool> visited(2 * n);
    visited[n] = true;

    while (!q.empty()) {
        int u{ q.front() };
        q.pop_front();

        for (auto v : adj[u]) {
            if (visited[v]) continue;
            q.push_back(v);
            visited[v] = true;
        }
    }

    int ans{};
    for (int i{}; i < n; ++i) {
        if (visited[i] && adj[i].empty()) ++ans;
    }

    cout << ans << '\n';

    return 0;
}