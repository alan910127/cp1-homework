#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

bool isVowel(char c) {
    static const string vowels{ "AEIOU" };
    return vowels.find(c) != string::npos;
}

bool isValid(const string& word) {
    int count[2]{}; // [vowel count, consonant count]
    bool Lflag{};

    for (char c : word) {
        int index = isVowel(c) ? 0 : 1;
        ++count[index];
        count[index ^ 1] = 0;
        if (count[index] >= 3) return false;
        if (c == 'L') Lflag = true;
    }

    return Lflag;
}

ll makePleasant(string& word, size_t index) {
    if (index >= word.length()) {
        return isValid(word) ? 1 : 0;
    }

    size_t nextUnderscore = word.find('_', index + 1);

    ll result = 0;
    word[index] = 'L';
    result += makePleasant(word, nextUnderscore);

    word[index] = 'A';
    result += 5 * makePleasant(word, nextUnderscore);

    word[index] = 'B';
    result += 20 * makePleasant(word, nextUnderscore);

    word[index] = '_';
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string word;
    cin >> word;
    cout << makePleasant(word, word.find('_')) << '\n';

    return 0;
}