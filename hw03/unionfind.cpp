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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    DisjointSets djs{ n };

    for (int i{}; i < q; ++i) {
        int a, b;
        char op;
        cin >> op >> a >> b;
        if (op == '=') djs.merge(a, b);
        else cout << (djs.is_same(a, b) ? "yes" : "no") << '\n';
    }

    return 0;
}