#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i{}; i < n; ++i) {
        int ans{};
        for (int j{}; j < n; ++j) {
            int num;
            cin >> num;
            ans |= num;
        }
        cout << ans << " \n"[i == n - 1];
    }

    return 0;
}