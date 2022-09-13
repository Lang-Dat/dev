#pragma GCC optimize("O2")
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("Tongsoam.INP", "r", stdin);
    freopen("Tongsoam.OUT", "w", stdout);

    int n, tmp, sum = 0;
    while (std::cin >> tmp)
    {
        if (tmp < 0)
            sum += tmp;    
    }

    std::cout << sum;
    
    return 0;
}   