#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

vector<ll> fib(3, 1);

char findLetter(ll n, ll k) {
    if (n == 1) return 'N';
    if (n == 2) return 'A';

    // s[n] = s[n - 2] + s[n - 1]
    if (n > fib.size() or k <= fib[n - 2]) return findLetter(n - 2, k);
    return findLetter(n - 1, k - fib[n - 2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 3; fib.back() <= 1e18; ++i) {
        fib.push_back(fib[i - 1] + fib[i - 2]);
    }

    ll n, k;
    cin >> n >> k;
    cout << findLetter(n, k) << '\n';

    return 0;
}