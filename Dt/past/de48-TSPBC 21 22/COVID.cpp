#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

int nums[5];
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./COVID.INP", "r", stdin);
    // freopen("./TestPBC2021_2022/COVID/Test13/COVID.INP", "r", stdin);
    freopen("./COVID.OUT", "w", stdout);

    int n, tmp, count = 0;   
    std::cin >> n;
    while(std::cin >> tmp)
        nums[tmp]++;
    count += std::min(nums[1], nums[3]);
    count += nums[3] - count;
    nums[1] -= count;
    nums[2] += (nums[1] > 0) ? nums[1] / 2 : 0;
    count += nums[2] / 2;
    if (nums[2] % 2 || nums[1] % 2) count++;
    count += nums[4];
    std::cout << count;
    return 0;
}