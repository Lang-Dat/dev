#pragma GCC optimize("O2")
#include <iostream>

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI2.INP", "r", stdin);
    freopen("./BAI2.OUT", "w", stdout);

    std::string str;
    ull W = 0, C = 0, ans = 0, n;
    std::cin >> n >> str;

    for (char c : str)
        if (c == 'W') W++;
    for (char c : str)
        if (c == 'O') ans += W * C;
        else if (c == 'C') C++;
        else if (c == 'W') W--;

    std::cout << ans;
    return 0;
}