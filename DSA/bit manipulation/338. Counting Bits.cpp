// https://leetcode.com/problems/counting-bits/
#include <iostream>
#include <vector>
#include <bitset>

// #define logl(x) std::cout << x << " --> " << std::bitset<4>(x) << " " << __builtin_popcount(x) << "\n";
std::vector<int> countBits(int n) {
    const unsigned int B = 32;
    std::vector<int> ans(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        unsigned int count = 0;
        for (int j = 0; j < B; j++)
            if ((i & (1 << j)) >= 1) {
                count++;
            }
        ans[i] = count;
    }
    return ans;
}

int main()
{
    // std::vector<int> nums = {1, 5, 6};
    // int n;
    // std::cin >> n;
    // for (int i = 0; i < n; i++) std::cin >> nums[i];
    auto ans = countBits(2);
    log(ans);
}