#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

int freq[10];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./Ts.INP", "r", stdin);
    freopen("./Ts.OUT", "w", stdout);

    int m;
    std::cin >> m;
    if (m == 0) {
        std::cout << 10 << "";
        return 0;
    }
    if (m == 1) {
        std::cout << 1 << "";
        return 0;
    }

    for (int i = 9; i > 1 ; i--)
        while(m % i == 0) {
            freq[i]++;
            m /= i;
        }
    if (m > 1) {
        std::cout << -1 << "";
        return 0;
    }
    
    for (int i = 2; i < 10; i++)
        for (int j = 0; j < freq[i]; j++)
            std::cout << i << "";
    return 0;
}