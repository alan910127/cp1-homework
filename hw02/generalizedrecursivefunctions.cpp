#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

// only support non-negative addition
class BigInteger {
public:
    BigInteger() : arr(1, 0) {}
    explicit BigInteger(long long num) {
        if (num == 0) {
            arr.assign(1, 0);
            return;
        }

        for (; num > 0; num /= 10) {
            arr.push_back(num % 10);
        }
    }
    BigInteger(const BigInteger& rhs) : arr{ rhs.arr } {}

    BigInteger& operator=(const BigInteger& rhs) {
        this->arr = rhs.arr;
        return *this;
    }

    BigInteger& operator+=(const BigInteger& rhs) {
        size_t sz1{ arr.size() }, sz2{ rhs.arr.size() };
        size_t newsize{ max(sz1, sz2) + 1 };

        arr.resize(newsize);

        for (size_t i{}; i < newsize - 1; ++i) {
            if (i < sz2) arr[i] += rhs[i];
            arr[i + 1] += arr[i] / 10;
            arr[i] %= 10;
        }

        while (arr.size() > 1 && arr.back() == 0) arr.pop_back();

        return *this;
    }

    friend ostream& operator<<(ostream& os, const BigInteger& rhs) {
        for (int i{ static_cast<int>(rhs.arr.size()) - 1 }; i >= 0; --i) {
            os << static_cast<int>(rhs[i]);
        }
        return os;
    }

private:
    vector<int8_t> arr;

    int8_t& operator[](size_t pos) { return arr[pos]; }
    int8_t operator[](size_t pos) const { return arr[pos]; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.get();

    stringstream ss{};

    while (n--) {
        string line;
        getline(cin, line);
        ss.clear();
        ss.str(line);

        vector<int> a{}, b{};

        int u, v;
        while (ss >> u >> v) {
            a.push_back(u);
            b.push_back(v);
        }

        int c{ a.back() }, d{ b.back() };
        a.pop_back();
        b.pop_back();

        getline(cin, line);
        ss.clear();
        ss.str(line);

        vector<int> x{}, y{};
        while (ss >> u >> v) {
            x.push_back(u);
            y.push_back(v);
        }

        vector<vector<optional<BigInteger>>> dp(100, vector<optional<BigInteger>>(100, nullopt));

        function<BigInteger(int, int)> f = [&](int x, int y) -> BigInteger {
            if (x <= 0 || y <= 0) return BigInteger{ d };
            if (dp[x][y]) return *dp[x][y];

            BigInteger ans{ c };
            for (size_t i{}; i < a.size(); ++i) {
                ans += f(x - a[i], y - b[i]);
            }

            return dp[x][y].emplace(ans);
        };

        for (size_t i{}; i < x.size(); ++i) {
            cout << f(x[i], y[i]) << '\n';
        }
        cout << '\n';
    }

    return 0;
}