#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

using Polynomial = valarray<complex<double>>;
const double PI = acos(-1);

// Smallest power of 2 greater than or equal to n.
ll nextPowewOf2(ll n) {
    --n;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n |= n >> 32;
    return n + 1;
}

// T(n) = T(n / 2) + O(n) => T(n) = O(n log n) by Master Theorem
void FFT(Polynomial& p) {
    ll n = p.size();
    if (n <= 1) return;

    Polynomial even{ p[slice(0, n / 2, 2)] }; // even = p[::2]
    Polynomial odd{ p[slice(1, n / 2, 2)] };  // odd = p[1::2]

    FFT(even);
    FFT(odd);

    for (ll j = 0; j < n / 2; ++j) {
        // std::polar(r, theta) = r (cos(theta) + i sin(theta))
        //                      = r * std::exp(theta * 1i)
        // omega = exp(2 pi i / n)  [root of unity]
        complex<double> t{ polar(1.0, 2.0 * PI * j / n) /* <- omega^j */ * odd[j] };
        p[j] = even[j] + t;
        p[j + n / 2] = even[j] - t;
    }
}

void IFFT(Polynomial& p) {
    // The inverse of a DFT (discrete fourier transform) matrix is simply the DFT matrix with replacing all the omega with (1 / n) * omega^(-1)
    // Since omega is a root of unity, omega^(-1) is the conjugate of itself
    // Note: x * conj(omega) = conj(conj(x) * omega)
    p = p.apply(conj);
    FFT(p);
    p = p.apply(conj);
    p /= p.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    // 1. We need at least str.length() points to represent p1 and p2 in point-value form (since they're both of degree str.length() - 1).
    // 2. Multiply two polynomials of degree d will produce a polynomial of degree 2d, thus multiply by 2.
    // 3. Find the next power of two to fit the requirement of FFT (the degree must be a power of 2).
    ll size = nextPowewOf2(str.length() << 1);

    Polynomial p1(size);
    Polynomial p2(size);

    for (ll i = 0; i < str.length(); ++i) {
        p1[i] = (str[i] == 'A') ? 1.0 : 0.0;
        p2[size - i - 1] = (str[i] == 'A') ? 0.0 : 1.0; // Still not understood
    }

    // Evaluation Step
    // Turn p1, p2 from coeffecient representation to value representation (or point-value form) by using FFT
    FFT(p1);
    FFT(p2);

    // Multiply the value representation of the two polynomials to get the value representation of the desired p
    for (ll i = 0; i < size; ++i) {
        p1[i] *= p2[i];
    }

    // Interpolation Step
    // Turn the result back to the coeffecient representation by using inverse FFT
    IFFT(p1);

    // The k-inversion is actually the coeffecient of the k-th term of the result p
    for (int i = 0; i < str.size() - 1; ++i) {
        cout << static_cast<int>(p1[i].real() + 0.25) << '\n';
    }

    return 0;
}