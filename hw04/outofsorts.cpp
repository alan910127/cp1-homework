#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll m, a, c, first;
    cin >> n >> m >> a >> c >> first;

    vector<int> sequence(n);
    for (int i = 0; i < n; ++i) {
        sequence[i] = (a * ((i == 0) ? first : sequence[i - 1]) + c) % m;
    }

    int ans{};
    for (int term : sequence) {
        int low = 0, high = n - 1; // [low, high]

        while (low <= high) {
            int mid = (low + high) / 2;
            int num = sequence[mid];

            if (num == term) {
                ++ans;
                break;
            }

            if (term < num) high = mid - 1;
            else low = mid + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}