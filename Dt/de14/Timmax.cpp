#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./Timmax.INP", "r", stdin);
    freopen("./Timmax.OUT", "w", stdout);

    int min_nums = INT32_MAX, ans = INT32_MIN, tmp, n;
    std::cin >> n >> min_nums;
    while(std::cin >> tmp) {
        ans = std::max(ans, tmp - min_nums);
        min_nums = std::min(min_nums, tmp);
    }
    std::cout << ans;


    return 0;
}