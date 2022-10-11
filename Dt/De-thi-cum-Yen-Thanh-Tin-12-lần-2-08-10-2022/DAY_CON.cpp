#pragma GCC optimize("O2")
#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
const int LIM = 1e5 + 5;
int n, q, tmp, k;
int nums[LIM];

void solve() {
    int best = 0, prev = -1;
    for (int i = 0; i < n; i++) {
        if (nums[i] > k) {
            best = std::max(best, i - prev - 1);
            prev = i;
        }
    }
    best = std::max(best, n - prev - 1);
    std::cout << best << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DAY_CON.INP", "r", stdin);
    // freopen("./DAY_CON.OUT", "w", stdout);

    std::cin >> n >> q;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    for (int i = 0; i < q; i++) {
        std::cin >> k;
        solve();
    }
    return 0;
}