#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>
#include <vector>

#define ull unsigned long long

const int LIM = 1e6;
ull nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./LENGTH.INP", "r", stdin);
    freopen("./LENGTH.OUT", "w", stdout);

    ull n, tmp, best = INT32_MAX, k;
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        std::cin >> tmp;
        nums[i] = tmp + nums[i - 1];
    }
    best = std::lower_bound(nums, nums + n, k) - nums;
    for (int i = 1; i < n && nums[n] - nums[i - 1] >= k; i++) {
        int r = std::lower_bound(nums + i + 1, nums + n, nums[i-1] + k) - nums;
        if (r == n && nums[r] - nums[i-1] < k) continue;
        if (r - i + 1 < best) {
            best = r - i + 1;
        }
    }
    std::cout << best;
    return 0;
}