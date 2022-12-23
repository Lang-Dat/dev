#pragma GCC optimize("O2")
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("DOANCON.INP", "r", stdin);
    freopen("DOANCON.OUT", "w", stdout);

    int n, tmp;
    bool allIsNegative = true; 
    std::cin >> n;
    int sum[n + 1];
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> tmp;
        sum[i] = tmp + sum[i-1];
        if (tmp >= 0) allIsNegative = false;
    }
    if (allIsNegative) {
        std::cout << -1;
        return 0;
    }
    // for (int i = 0; i <= n; i++)
    //     std::cout << sum[i] << " ";
    int max = 1;
    for (int l = 0; l < n; l++)
        for (int r = n; r > l && max < r - l; r--)
            if (sum[r] - sum[l] >= 0 && r - l > max)
                {
                    max = r - l;
                    break;
                }

    std::cout << max;
    return 0;
}