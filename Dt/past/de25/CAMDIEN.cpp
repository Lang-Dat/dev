#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./CAMDIEN.INP", "r", stdin);
    freopen("./CAMDIEN.OUT", "w", stdout);

    int n, m, count = 0, tmp;
    std::cin >> n >> m;
    int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        nums[i] = tmp-1;
    }
    std::sort(nums, nums + n, std::greater<int>());
    nums[0]++;
    for (int i = 0; i < n && m > 0; i++, count++)
        m -= nums[i];
    if (m > 0) std::cout << -1;
    else std::cout << count;


    return 0;
}