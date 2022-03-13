#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> height(n);
    for (auto& h : height) {
        cin >> h;
    }

    sort(height.rbegin(), height.end());

    int ans{ n };
    for (int i{}; i < n; ++i) {
        ans = min(ans, height[i] + i);
    }

    cout << ans << '\n';

    return 0;
}