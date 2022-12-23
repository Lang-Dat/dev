#pragma GCC optimize("O2")
#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI5.INP", "r", stdin);
    // freopen("./test/BAI5/test6/BAI5.INP", "r", stdin);
    freopen("./BAI5.OUT", "w", stdout);

    int n, tmp, count = 0;
    std::cin >> n;
    std::vector<int> sum(n+1, 0);
    for (int i = 1; i <= n; i++) {
        std::cin >> tmp;
        sum[i] = sum[i-1] + tmp;
    }
    
    for (int i = 0; i < n; i++) {
        if (3 * sum[i] == sum[n] - sum[i])
            for (int j = i + 1; j < n; j++)
                if (sum[j] - sum[i] == sum[i] && sum[n] - sum[j] == 2 * sum[i])
                    for (int k = j + 1; k < n; k++)
                        if (sum[k] - sum[j] == sum[i])
                            count++;
    }
    std::cout << count;

    return 0;
}