#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    const int movei[]{ 1, 1, 1, 0, -1, -1, -1, 0 };
    const int movej[]{ 1, 0, -1, -1, -1, 0, 1, 1 };

    vector<string> grid(n);
    for (auto& row : grid) cin >> row;

    int ans{};
    for (int i{}; i < n; ++i) {
        for (int j{}; j < m; ++j) {
            if (grid[i][j] != '#') continue;

            ++ans;
            deque<pii> q{ pii{ i, j } };
            grid[i][j] = '.';

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop_front();

                for (int k{}; k < 8; ++k) {
                    int nexti{ x + movei[k] };
                    int nextj{ y + movej[k] };
                    if (nexti < 0 || nexti >= n || nextj < 0 || nextj >= m) continue;
                    if (grid[nexti][nextj] == '#') {
                        q.emplace_back(nexti, nextj);
                        grid[nexti][nextj] = '.';
                    }
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}