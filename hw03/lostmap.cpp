#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

struct Edge {
    int u;
    int v;
    int w;

    Edge() = default;
    Edge(int u, int v, int w) : u{ u }, v{ v }, w{ w } {} 

    bool operator<(const Edge& e) const { return w < e.w; }
};

struct DisjointSets {
    vector<int> arr;
    DisjointSets(size_t N) : arr(N, -1) {}

    int find(int x) {
        if (arr[x] < 0) return x;
        return arr[x] = find(arr[x]);
    }

    bool merge(int x, int y) {
        int px{ find(x) }, py{ find(y) };
        if (px == py) return false;

        if (arr[px] < arr[py]) {
            arr[px] += arr[py];
            arr[py] = px;
        }
        else {
            arr[py] += arr[px];
            arr[px] = py;
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Edge> edges;

    for (int i{}; i < n; ++i) {
        for (int j{}; j < n; ++j) {
            int x;
            cin >> x;
            if (i < j) edges.emplace_back(i, j, x);
        }
    }

    sort(edges.begin(), edges.end());

    DisjointSets djs(n);
    for (auto& [u, v, _] : edges) {
        if (djs.merge(u, v)) {
            cout << u + 1 << ' ' << v + 1 << '\n';
        }
    }

    return 0;
}