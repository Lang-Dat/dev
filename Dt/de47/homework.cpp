#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./homework.INP", "r", stdin);
    freopen("./homework.OUT", "w", stdout);

    ull n, s, count = 0;
    std::cin >> n >> s;
    int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    std::sort(nums, nums + n);
    for (int i : nums) {
        if (s >= i) {
            count++;
            s += i;
        } else {
            break;
        }
    }
    std::cout << count;
    return 0;
}