#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>
#include <vector>

int tongChuSo(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SAPXEP.INP", "r", stdin);
    freopen("./SAPXEP.OUT", "w", stdout);

    int n;
    std::cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
        std::cin >> nums[i];
    std::sort(nums, nums + n, [](int a, int b) -> bool {
        return tongChuSo(a) < tongChuSo(b);
    });
    for (int i : nums)
        std::cout << i << " ";
    return 0;
}