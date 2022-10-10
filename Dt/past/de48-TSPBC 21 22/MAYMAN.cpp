#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

const int LIM = 1e7;
int nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./MAYMAN.INP", "r", stdin);
    freopen("./MAYMAN.OUT", "w", stdout);

    int n, p, l = 0, r = 0, best = 0, min = 0, max = 0;
    std::cin >> n >> p;
    std::cin >> nums[0];
    min = nums[0];
    for (int i = 1; i < n; i++) {
        std::cin >> nums[i];
        max = std::max(nums[i], max);
        best = std::max(max - min, best);
        min = std::min(nums[i], min);
    }
    if (best < p) {
        std::cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j - i > l - r && j > i; j--) {
            if (nums[j] - nums[i] >= p) {
                r = i;
                l = j;
                break;
            } 
        }
    }
    std::cout << r + 1 << " " << l + 1;
    return 0;
}