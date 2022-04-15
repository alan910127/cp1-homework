#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

struct FenwickTree {
    vector<ll> arr;
    FenwickTree(size_t N) : arr(N + 1, 0) {}

    void modify(int x, ll value) {
        for (; x < arr.size(); x += (x & -x)) {
            arr[x] += value;
        }
    }

    ll query(int x) {
        ll result{};
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

        if (op == '+') {
            int idx, delta;
            cin >> idx >> delta;
            fenwick.modify(idx + 1, delta);
        }
        else {
            int idx;
            cin >> idx;
            cout << fenwick.query(idx) << '\n';
        }
    }

    return 0;
}