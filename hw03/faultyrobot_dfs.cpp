#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> forced(n, -1);

    for (int i{}; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --v;

        if (u < 0) {
            u = -u - 1;
            forced[u] = v;
        }
        else {
            --u;
            adj[u].push_back(v);
        }
    }

    int ans{};
    vector<bool> visited(n, false);

    function<void(int, int)> dfs{
        [&](int u, int d) {
            if (d < 0) return;
            if (visited[u]) return;
            visited[u] = true;

            if (forced[u] != -1) dfs(forced[u], d);
            else ++ans;

            for (auto v : adj[u]) {
                dfs(v, d - 1);
            }
    }
    };

    dfs(0, 1);
    cout << ans << '\n';

    return 0;
}