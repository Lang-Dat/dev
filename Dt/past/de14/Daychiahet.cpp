#pragma GCC optimize("O2")
#include <iostream>
#include <vector>

#define ull unsigned long long
std::vector<ull> nums;
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./Daychiahet.INP", "r", stdin);
    freopen("./Daychiahet.OUT", "w", stdout);

    int n;
    std::cin >> n;
    nums.reserve(n + 1);
    nums.push_back(1);
    for (int i = 2; nums.size() < n;i++)
        for (ull count = 0, j = nums.back() / i * i + i; nums.size() < n && count < i; count++, j += i)
            nums.push_back(j);
    std::cout << nums[n-1];

    return 0;
}