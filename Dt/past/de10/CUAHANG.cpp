#pragma GCC optimize("O2")
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./CUAHANG.INP", "r", stdin);
    freopen("./CUAHANG.OUT", "w", stdout);

    int n, sum = 0, currMax = INT32_MIN, dayMax = INT32_MIN, tmp;
    std::cin >> n;
    if (n <= 0) return 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> tmp;
        sum += tmp;
        if (tmp > currMax) {
            currMax = tmp;
            dayMax = i;
        }
    }
    std::cout << sum << "\n" << dayMax;
    return 0;
}