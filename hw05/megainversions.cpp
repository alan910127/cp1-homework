#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

struct FenwickTree {
    vector<ll> arr;
    FenwickTree(size_t N) : arr(N + 1, 0) {}

    void modify(int x, int value) {
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

    ll query(int left, int right) {
        // [left, right]
        return query(right) - query(left - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    FenwickTree numbers(n);
    FenwickTree fenwick(n);

    ll ans{};
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        numbers.modify(num, 1);
        fenwick.modify(num, numbers.query(num + 1, n));
        ans += fenwick.query(num + 1, n);

        // 45: numbers_count[num] += 1;
        //     We have one more integer that is 'num', so store it.

        // 46: two_inversions_count[num] += sum( numbers_count[ num + 1 : n ] )
        //     Add the number of integers greater than num to two_inversions_count[num],
        //      so that fenwick[num] is now the number of pairs (ai, num) where ai is appeared earlier than num (trivailly)
        //      and is greater than num (thus form a 2-inversion with the smaller one is num).

        // 47: answer += sum( two_inversions_count[ num + 1 : n ] )
        //     Add two_inversions_count[num + 1 : n] to the answer,
        //      while we know that two_inversions_count[num + 1:n] is the number of all 2-inversions(ai, aj)
        //      with that aj is greater than num.
    }

    cout << ans << '\n';

    return 0;
}