#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI4.INP", "r", stdin);
    freopen("./BAI4.OUT", "w", stdout);

    int n, digitCount = 0;
    std::cin >> n;

    for (; n >= std::pow(2, digitCount) - 1.f; digitCount++)
        n -= std::pow(2, digitCount);
    digitCount--;
    for (int i = digitCount; i >= 0; i--)
        if (n & (1 << i))
            std::cout << "7";
        else 
            std::cout << "4";
    return 0;
}