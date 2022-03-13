#include <bits/stdc++.h>
using namespace std;

bool ishex(char c) {
    return isdigit(c) || (isalpha(c) && tolower(c) <= 'f');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    while (getline(cin, str)) {
        for (int i{}; i < str.length(); ++i) {
            if (str[i] == '0' && i + 1 < str.length() && tolower(str[i + 1]) == 'x') {
                string num{ str.substr(i, 2) };
                for (i += 2; i < str.length() && ishex(str[i]); ++i) num += str[i];
                if (num.length() > 2) cout << num << ' ' << stoll(num, nullptr, 16) << '\n';
            }
        }
    }

    return 0;
}