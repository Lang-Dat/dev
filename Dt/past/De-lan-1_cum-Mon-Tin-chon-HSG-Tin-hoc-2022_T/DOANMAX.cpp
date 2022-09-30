#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

const int LIM = 1e6 + 6;
int nums[LIM], dp[LIM], out[LIM];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DOANMAX.INP", "r", stdin);
    freopen("./DOANMAX.OUT", "w", stdout);

    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
        for (int j = 0; j < i; j++)
            if (dp[j] + 1 > dp[i] && nums[i] >= nums[j]) {
                dp[i] = dp[j] + 1;
                out[i] = j;
            }
    }
    auto itr = std::max_element(dp, dp + n);
    std::vector<int> ans;
    ans.reserve(*itr + 1);

    std::cout << *itr + 1 << "\n";
    for (int i = itr - dp, count = *itr + 1; count > 0; i = out[i], count--)
        ans.push_back(nums[i]);
    for (int i = ans.size() - 1; i >= 0; i--)
        std::cout << ans[i] << " ";
    return 0;
}