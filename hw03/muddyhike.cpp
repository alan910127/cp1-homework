#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

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

struct node {
    int row;
    int col;
    int val;
    node() = default;
    node(int row, int col, int val) : row{ row }, col{ col }, val{ val }{}
    bool operator<(const node& n) const { return val < n.val; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;
    cin >> r >> c;

    vector<node> nodes;
    for (int i{}; i < r; ++i) {
        for (int j{}; j < c; ++j) {
            int x;
            cin >> x;
            nodes.emplace_back(i, j, x);
        }
    }

    sort(nodes.begin(), nodes.end());

    vector<bool> visited(r * c, false);
    DisjointSets djs(r * c + 2);
    // r * c => fake start
    // r * c + 1 => fake end

    int dr[]{ 1, 0, -1, 0 };
    int dc[]{ 0, 1, 0, -1 };

    function<int(int, int)> indexOf = [c](int i, int j) { return i * c + j; };

    for (auto [row, col, val] : nodes) {
        visited[indexOf(row, col)] = true;

        for (int k{}; k < 4; ++k) {
            int nr{ row + dr[k] }, nc{ col + dc[k] };
            if (nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
            if (visited[indexOf(nr, nc)]) {
                djs.merge(indexOf(row, col), indexOf(nr, nc));
            }
        }

        if (col == 0) djs.merge(indexOf(row, col), r * c);
        if (col == c - 1) djs.merge(indexOf(row, col), r * c + 1);

        if (djs.is_same(r * c, r * c + 1)) {
            cout << val << '\n';
            break;
        }
    }

    return 0;
}