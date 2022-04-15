#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

struct FenwickTree {
    vector<int> arr;
    vector<bool> memory;
    FenwickTree(size_t N) : arr(N + 1, 0), memory(N + 1, false) {}

    void flip(int x) {
        this->modify(x, memory[x] ? -1 : 1);
        memory[x].flip();
    }

    int query(int left, int right) {
        return query(right) - query(left - 1);
    }

    void modify(int x, int value) {
        for (; x < arr.size(); x += (x & -x)) {
            arr[x] += value;
        }
    }

    int query(int x) {
        int result{};
        for (; x > 0; x -= (x & -x)) {
            result += arr[x];
        }
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    FenwickTree fenwick(n);

    while (q--) {
        char op;
        cin >> op;

        if (op == 'F') {
            int idx;
            cin >> idx;
            fenwick.flip(idx);
        }
        else {
            int left, right;
            cin >> left >> right;
            cout << fenwick.query(left, right) << '\n';
        }
    }

    return 0;
}