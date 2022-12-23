#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./FAMILIAR.INP", "r", stdin);
    freopen("./FAMILIAR.OUT", "w", stdout);

    int n, best = 0, best_index, ans = 0;
    std::cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
        std::cin >> nums[i];
    
    std::sort(nums, nums + n);

    for (int i = 0; i < n; i++) {
        nums[i] += n - i;
        if (nums[i] >= best) { // lay chi muc cua so sau cung
            best = nums[i];
            best_index = i;
        }
    }

    for (int i = 0; i < n; i++) {
        int now = nums[i] - (n - i) + n;
        if (i == best_index || (i > best_index && now >= best - 1) ||
            (i < best_index && now >= best)) ans++;
    }
    std::cout << ans;
    return 0;
}