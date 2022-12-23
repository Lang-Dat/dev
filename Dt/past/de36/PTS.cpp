#pragma GCC optimize("O2")
#include <iostream>
#include <vector>

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./PTS.INP", "r", stdin);
    freopen("./PTS.OUT", "w", stdout);

    ull n;
    std::vector<ull> ans;
    std::cin >> n;
    for (ull i = 2; i < n; i++)
        while (n % i == 0) {
            ans.push_back(i);
            n /= i;
        }
    if (n > 1)
        ans.push_back(n);
    for (int i = 0; i < ans.size() - 1; i++)
        std::cout << ans[i] << ".";
    std::cout << ans.back() << "";
    return 0;
}