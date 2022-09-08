#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("GAME.INP", "r", stdin);
    freopen("GAME.OUT", "w", stdout);

    int n;
    std::cin >> n;
    short nums[n];
    for (int i = 0; i < n; i++)
        std::cin >> nums[i];

    std::sort(nums, nums + n);
    if (n >= 3) std::cout <<  nums[n-1] + nums[n-2] + nums[n-3];
    else if (n == 2) std::cout <<  nums[n-1] + nums[n-2];
    else if (n == 1) std::cout <<  nums[0];
    return 0;
}