#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

struct FenwickTree {
    vector<int> arr;
    FenwickTree(size_t N) : arr(N + 1, 0) {}

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

    int query(int left, int right) {
        return query(right) - query(left - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    ll values[6];
    for (auto& value : values) cin >> value;

    vector<FenwickTree> fenwick(6, FenwickTree(n));

    vector<int> types(n + 1);
    string str;
    cin >> str;
    for (int i = 1; i <= n; ++i) {
        types[i] = (str[i - 1] - '0') - 1;
        fenwick[types[i]].modify(i, 1);
    }

    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            fenwick[types[x]].modify(x, -1);
            types[x] = y - 1;
            fenwick[types[x]].modify(x, 1);
        }
        else if (op == 2) {
            values[x - 1] = y;
        }
        else {
            ll sum{};
            for (int i = 0; i < 6; ++i) {
                sum += fenwick[i].query(x, y) * values[i];
            }
            cout << sum << '\n';
        }
    }

    return 0;
}