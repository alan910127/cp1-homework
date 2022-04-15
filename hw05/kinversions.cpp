#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using fftvector = valarray<complex<double>>;
const double PI = acos(-1);

ll nextPow2(ll n) {
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    return n + 1;
}

void fft(fftvector& vec) {
    ll sz = vec.size();
    if (sz <= 1) return;

    fftvector even{ vec[slice(0, sz / 2, 2)] };
    fftvector odd{ vec[slice(1, sz / 2, 2)] };

    fft(even);
    fft(odd);

    for (ll i = 0; i < sz / 2; ++i) {
        complex<double> t{ polar(1.0, -2.0 * PI * i / sz) * odd[i] };
        vec[i] = even[i] + t;
        vec[i + sz / 2] = even[i] - t;
    }
}

void ifft(fftvector& vec) {
    vec = vec.apply(conj);
    fft(vec);
    vec = vec.apply(conj);
    vec /= vec.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    ll size = nextPow2(str.length() + 1) << 1;

    fftvector v1(size);
    fftvector v2(size);

    for (ll i = 0; i < str.length(); ++i) {
        v1[i] = (str[i] - 'A') ^ 1;
        v2[size - i - 1] = (str[i] - 'A');
    }

    fft(v1);
    fft(v2);

    for (ll i = 0; i < size; ++i) {
        v1[i] *= v2[i];
    }

    ifft(v1);

    for (int i = 0; i < str.size() - 1; ++i) {
        cout << static_cast<int>(v1[i].real() + 0.25) << '\n';
    }

    return 0;
}