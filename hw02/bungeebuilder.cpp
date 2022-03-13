#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> height(n);
    for (auto& h : height) {
        cin >> h;
    }

    int ans{};
    vector<pii> stack{}; // (highest, lowest)
    for (int i = 0; i < n; ++i) {
        int lowest{ height[i] };

        while (!stack.empty()) {
            auto [H, L] = stack.back();
            stack.pop_back();

            lowest = min(lowest, L);

            if (H > height[i]) {
                stack.emplace_back(H, lowest);
                ans = max(ans, height[i] - lowest);
                break;
            }

            ans = max(ans, H - lowest);
        }

        stack.emplace_back(height[i], height[i]);
    }

    cout << ans << '\n';

    return 0;
}