#pragma GCC optimize("O2")
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI1.INP", "r", stdin);
    freopen("./BAI1.OUT", "w", stdout);

    char c;
    std::vector<char> nums;
    nums.reserve((int)1e5 + 5);
    while (std::cin >> c)
        nums.push_back(c);
    std::sort(nums.begin(), nums.end(), std::greater<int>());
    for (char c : nums)
        std::cout << c;

    return 0;
}