#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

struct DisjointSets {
    vector<int> arr;
    vector<bool> count;

    DisjointSets(size_t N) : arr(N, -1), count(N, true) {}

    int find(int x) {
        if (arr[x] < 0) return x;
        return arr[x] = find(arr[x]);
    }

    void merge(int x, int y) {
        int px{ find(x) }, py{ find(y) };
        if (px == py) return;

        if (arr[px] < arr[py]) {
            arr[px] += arr[py];
            arr[py] = px;
        }
        else {
            arr[py] += arr[px];
            arr[px] = py;
        }
    }

    void disable(int x) {
        count[find(x)] = false;
    }

    int sum() {
        int ans{};
        for (size_t i{}; i < arr.size(); ++i) {
            if (arr[i] < 0 && count[i]) ans += -arr[i];
        }
        return ans;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> m >> n;

    vector<vector<int>> grid(n, vector<int>(m));
    for (auto& v : grid) {
        for (auto& i : v) {
            cin >> i;
        }
    }

    const int di[]{ 1, 0, -1, 0 };
    const int dj[]{ 0, 1, 0, -1 };

    DisjointSets djs(n * m);
    for (int i{}; i < n; ++i) {
        for (int j{}; j < m; ++j) {
            for (int k{}; k < 4; ++k) {
                int ni{ i + di[k] }, nj{ j + dj[k] };
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if (grid[i][j] == grid[ni][nj]) djs.merge(i * m + j, ni * m + nj);
            }
        }
    }

    for (int i{}; i < n; ++i) {
        for (int j{}; j < m; ++j) {
            for (int k{}; k < 4; ++k) {
                int ni{ i + di[k] }, nj{ j + dj[k] };
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if (grid[i][j] > grid[ni][nj]) djs.disable(i * m + j);
            }
        }
    }

    cout << djs.sum() << '\n';

    return 0;
}