#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, p;
    cin >> n >> m >> p;

    vector<int> crank(n);
    for (int& c : crank) {
        cin >> c;
    }

    vector<int> wheel(m);
    for (int& w : wheel) {
        cin >> w;
    }

    vector<double> cadence;
    for (int i : crank) {
        for (int j : wheel) {
            cadence.push_back(static_cast<double>(i) / j);
        }
    }

    sort(cadence.begin(), cadence.end());
    bool flag{ true };
    for (int i{}; i < cadence.size() - 1 && flag; ++i) {
        if (cadence[i + 1] / cadence[i] > 1 + p * 0.01) flag = false;
    }

    cout << (flag ? "Ride on!" : "Time to change gears!") << '\n';

    return 0;
}