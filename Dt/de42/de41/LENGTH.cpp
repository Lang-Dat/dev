#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./LENGTH.INP", "r", stdin);
    freopen("./LENGTH.OUT", "w", stdout);

    int n, tmp, best = INT32_MAX, k;
    std::cin >> n >> k;
    ull nums[n + 1];
    nums[0] = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> tmp;
        nums[i] = tmp += nums[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        int r = std::lower_bound(nums + i + 1, nums + n, nums[i-1] + k) - nums;
        best = std::min(best, r - i + 1);
    }
    std::cout << best;
    return 0;
}