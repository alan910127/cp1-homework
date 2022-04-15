//
// I don't understand this.
//

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

inline int mqpow(int base, int power, int mod) {
    int result{ 1 };
    while (power > 0) {
        if (power & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        power >>= 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    if (a & 1) cout << 0 << '\n';
    else cout << mqpow(a / 2, b, a) << '\n';

    return 0;
}