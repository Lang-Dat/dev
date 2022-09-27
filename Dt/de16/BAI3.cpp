#pragma GCC optimize("O2")
#include <iostream>
#include <vector>
#include <algorithm>

const int LIM = 1e6 + 1;
std::vector<int> nums(LIM, 0);
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI3.INP", "r", stdin);
    freopen("./BAI3.OUT", "w", stdout);

    int n, k, c, x, max = 0;
    std::cin >> n >> k;
    k = k * 2 + 1;
    while (std::cin >> c >> x)
        nums[x] += c;
    for (int i = 1; i < LIM; i++)
        nums[i] += nums[i - 1];
    for (int i = 1; i + k < LIM; i++)
        if (nums[i + k] - nums[i-1] > max)
            max = nums[i + k] - nums[i-1];
    if (k >= LIM) max = nums[LIM-1];
    else max = std::max(max, nums[LIM - 1] - nums[LIM - k - 1]);
    std::cout << max;
    return 0;
}