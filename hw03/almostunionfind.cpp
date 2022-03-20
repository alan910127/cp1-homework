#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;


struct DisjointSets {
    vector<int> rep, num, idx;
    vector<ll> sum;

    DisjointSets(size_t N) : rep(N, -1), idx(N), sum(N) {
        for (size_t i{}; i < N; ++i) {
            sum[i] = idx[i] = i;
        }
    }

    int find(int x) {
        if (rep[x] < 0) return x;
        return rep[x] = find(rep[x]);
    }

    void merge(int x, int y) {
        int px{ find(x) }, py{ find(y) };
        if (px == py) return;

        if (rep[px] > rep[py]) swap(px, py);
        rep[px] += rep[py];
        sum[px] += sum[py];
        rep[py] = px;
    }

    void move(int x, int y) {
        int px{ find(idx[x]) }, py{ find(idx[y]) };
        if (px == py) return;

        rep[px] -= -1;
        sum[px] -= x;

        idx[x] = rep.size();
        rep.push_back(-1);
        sum.push_back(x);

        merge(idx[x], py);
    }

    int get(int x) {
        return idx[x];
    }

    int card(int x) {
        return -rep[find(idx[x])];
    }

    ll sumElm(int x) {
        return sum[find(idx[x])];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) { // several test cases, fuk ==
        DisjointSets djs(n + 1);
        for (int i{}; i < m; ++i) {
            int op;
            cin >> op;
            if (op == 1) {
                int p, q;
                cin >> p >> q;
                djs.merge(djs.get(p), djs.get(q));
            }
            else if (op == 2) {
                int p, q;
                cin >> p >> q;
                djs.move(p, q);
            }
            else {
                int p;
                cin >> p;
                cout << djs.card(p) << ' ' << djs.sumElm(p) << '\n';
            }
        }
    }

    return 0;
}