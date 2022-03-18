#include <bits/stdc++.h>
using namespace std;

struct DisjointSets {
    vector<int> arr;
    DisjointSets(size_t N) : arr(N, -1) {}

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

    bool is_same(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    DisjointSets djs{ n };

    for (int i{}; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        djs.merge(u - 1, v - 1);
    }

    bool flg{ true };
    for (int i = 1; i < n; ++i) {
        if (!djs.is_same(0, i)) {
            flg = false;
            cout << i + 1 << '\n';
        }
    }

    if (flg) cout << "Connected\n";

    return 0;
}