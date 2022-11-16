#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

#define ull unsigned long long

const int LIM = 1e6 + 5;
ull nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI5.INP", "r", stdin);
    freopen("./BAI5.OUT", "w", stdout);

    ull n, k, c, x, best = 0;
    std::cin >> n >> k;
    k = k * 2 + 1;
    for (int i = 0; i < n; i++) {
        std::cin >> c >> x;
        nums[x] = c;
    }
    for (int i = 1; i < LIM; i++)
        nums[i] += nums[i-1];
    for (int i = 1; i + k < LIM; i++)
            best = std::max(best, nums[i + k - 1] - nums[i - 1]);
    if (k >= LIM) best = std::max(best, nums[LIM-1]);
    std::cout << best;
    return 0;
}