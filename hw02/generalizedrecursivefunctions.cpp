#include <bits/stdc++.h>
using namespace std;

// only support non-negative addition
class BigInteger {
public:
    BigInteger();
    explicit BigInteger(long long num);
    BigInteger(const BigInteger& rhs);
    BigInteger& operator=(const BigInteger& rhs); // not needed, just implement to follow OOP principles

    BigInteger& operator+=(const BigInteger& rhs);
    friend ostream& operator<<(ostream& os, const BigInteger& rhs);

private:
    vector<short> arr;

    short& operator[](size_t pos);
    short operator[](size_t pos) const;
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

BigInteger::BigInteger() : arr{ 0 } {}

BigInteger::BigInteger(long long num) {
    for (; num > 0; num /= 10) {
        arr.push_back(num % 10);
    }
    if (arr.empty()) arr.push_back(0);
}

BigInteger::BigInteger(const BigInteger& rhs) : arr{ rhs.arr } {}

BigInteger& BigInteger::operator=(const BigInteger& rhs) {
    this->arr = rhs.arr;
    return *this;
}

BigInteger& BigInteger::operator+=(const BigInteger& rhs) {
    size_t sz1{ arr.size() }, sz2{ rhs.arr.size() };
    size_t newsize{ max(sz1, sz2) + 1 };

    arr.resize(newsize, 0);

    for (size_t i{}; i < newsize - 1; ++i) {
        if (i < sz2) arr[i] += rhs[i];
        arr[i + 1] += arr[i] / 10;
        arr[i] %= 10;
    }

    while (arr.size() > 1 && arr.back() == 0) arr.pop_back();

    return *this;
}

ostream& operator<<(ostream& os, const BigInteger& rhs) {
    for (auto it{ rhs.arr.crbegin() }; it != rhs.arr.crend(); ++it) {
        os << *it;
    }
    return os;
}

short& BigInteger::operator[](size_t pos) {
    return arr[pos];
}

short BigInteger::operator[](size_t pos) const {
    return arr[pos];
}