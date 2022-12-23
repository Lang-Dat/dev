#pragma GCC optimize("O2")
#include <iostream>
#include <unordered_set>

std::unordered_set<char> soLe = {'1', '3', '5', '7', '9'};
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./COUNT.INP", "r", stdin);
    freopen("./COUNT.OUT", "w", stdout);

    std::string str;
    std::getline(std::cin, str);
    int ans = 0;
    for (char c : str)
        if (soLe.count(c))
            ans++;
    std::cout << ans;
    return 0;
}