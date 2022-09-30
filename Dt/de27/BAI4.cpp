#pragma GCC optimize("O2")
#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI4.INP", "r", stdin);
    // freopen("./test/BAI4/test5/BAI4.INP", "r", stdin);
    freopen("./BAI4.OUT", "w", stdout);

    int n, k, tmp, best = 0;
    std::cin >> n >> k;
    std::vector<int> sum(n+1, 0);
    for (int i = 1; i <= n; i++) {
        std::cin >> tmp;
        sum[i] = sum[i-1] + tmp;
    }
    for (int i = 1; i < n; i++)
        for (int j = n; j > i && j - i + 1> best; j--)
            if ((sum[j] - sum[i-1]) % k == 0)
                best = j - i + 1;
    std::cout << best;
    return 0;
}