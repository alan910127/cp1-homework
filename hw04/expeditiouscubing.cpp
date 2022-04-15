#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);

    int scores[4]{};
    for (int& score : scores) {
        int decimal, fractional;
        scanf("%d.%d", &decimal, &fractional);
        score = decimal * 100 + fractional;
    }

    sort(begin(scores), end(scores));

    int target;
    {
        int decimal, fractional;
        scanf("%d.%d", &decimal, &fractional);
        target = decimal * 100 + fractional;
    }

    function<bool(int)> available = [&](int finalScore) -> bool {
        int totalScore{ scores[1] + scores[2] };

        if (finalScore < scores[0]) totalScore += scores[0]; // @ [0 1 2] 3
        else if (finalScore > scores[3]) totalScore += scores[3]; // 0 [1 2 3] @
        else totalScore += finalScore;  // 0 [@ 1 @ 2 @] 3

        return totalScore <= target * 3;
    };

    int ans = 0, step = (1 << 10);
    while (step > 0) {
        if (available(ans + step)) ans += step;
        step >>= 1;
    }

    if (ans == 0) puts("impossible");
    else if (ans >= 2000) puts("infinite");
    else printf("%d.%02d\n", ans / 100, ans % 100);

    return 0;
}