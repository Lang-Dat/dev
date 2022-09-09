#pragma GCC optimize("O2")
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("XOASO.INP", "r", stdin);
    freopen("XOASO.OUT", "w", stdout);

    int n, sum = 0, even = 0, odd = 0, tmp;
    std::cin >> n;
    while(n--) {
        std::cin >> tmp;
        sum += tmp;
        if (tmp % 2 == 0) even++;
        else odd++;
    }

    if (sum % 2 == 0)
        std::cout << (even * (even+1) / 2) + (odd * (odd+1) / 2);
    else 
        std::cout << even * odd; 
    return 0;
}