#pragma GCC optimize("O2")
#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BMARKET.INP", "r", stdin);
    freopen("./BMARKET.OUT", "w", stdout);

    int n, k, y;
    std::cin >> y >> k >> n;

    std::vector<int> ans;

    for (int i = n / k * k; i > y; i -= k)
            ans.push_back(i - y);
    if (ans.empty())
        std::cout << -1;
    else 
        for (int i = ans.size() - 1; i >= 0; i--)
            std::cout << ans[i] << " ";

    return 0;
}