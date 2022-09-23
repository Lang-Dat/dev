#pragma GCC optimize("O2")
#include <iostream>

int maxDigit(int n) {
    int max = 0;
    while (n > 0)
    {
        if (n % 10 > max) max = n % 10;
        n /= 10;
    }
    return max;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DECREASE.INP", "r", stdin);
    freopen("./DECREASE.OUT", "w", stdout);

    int n, countStep = 0;
    std::cin >> n;
    while (n > 0)
    {
        countStep++;
        n -= maxDigit(n);
    }
    std::cout << countStep;
    return 0;
}