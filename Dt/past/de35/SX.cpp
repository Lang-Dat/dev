#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SX.INP", "r", stdin);
    // freopen("./TEST/SX/TEST1/SX.INP", "r", stdin);
    freopen("./SX.OUT", "w", stdout);

    int n;
    std::cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
        std::cin >> nums[i];
    std::sort(nums, nums + n);
    for (int i = 0; i < n / 2; i++)
        std::cout << nums[i] << " ";
    std::sort(nums, nums + n, std::greater<int>());
    for (int i = 0; i < n / 2; i++)
        std::cout << nums[i] << " ";
    return 0;
}