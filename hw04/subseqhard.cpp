#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;

    unordered_map<int, size_t> prefixSum;
    prefixSum[0] = 1;

    int sum{}, ans{};

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        sum += num;

        if (prefixSum.find(sum - 47) != prefixSum.end()) { // sum - (sum - 47) == 47
            ans += prefixSum[sum - 47];
        }
        ++prefixSum[sum];
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int nCases;
    cin >> nCases;

    while (nCases--) solve();

    return 0;
}