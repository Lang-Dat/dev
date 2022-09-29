#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

int main()
{   
    Timer time;
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("DOANCON.INP", "r", stdin);
    freopen("../../de55/Botest/DOANCON/Test12/DOANCON.INP", "r", stdin);
    freopen("DOANCON.OUT", "w", stdout);

    int n, tmp, best = -1;
    std::cin >> n;
    int sum[n + 1];
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> tmp;
        sum[i] = tmp + sum[i-1];
    }
    // for (int i = 0; i <= n; i++)
    //     std::cout << sum[i] << " ";
    for (int r = 0; r <= n; r++)
        for (int l = 0; l < r && r - l > best; l++)
            if (sum[r] - sum[l] >= 0) {
                best = r - l;
                break;
            }
    std::cout << best << "\n";
    return 0;
}