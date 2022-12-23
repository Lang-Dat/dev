#pragma GCC optimize("O2")
#include <iostream>
#include <cstring>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./CS.INP", "r", stdin);
    freopen("./CS.OUT", "w", stdout);

    std::string num;
    std::cin >> num;
    char max;
    int sum = 0;
    for (char c : num) {
        sum += (int)(c - '0');
        if (c > max) max = c;
    }    
    std::cout << sum << "\n" << max;

    return 0;
}