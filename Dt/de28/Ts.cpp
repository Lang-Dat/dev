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

    for (int i = 2; i < 10; i++)
        while(m % i == 0) {
            freq[i]++;
            m /= i;
        }
    if (m > 1) {
        std::cout << -1 << "";
        return 0;
    }
    freq[8] = freq[2] / 3;
    freq[2] %= 3;
    freq[9] = freq[3] / 2;
    freq[3] %= 2;
    int tmp = std::min(freq[2], freq[3]);
    freq[6] += tmp;
    freq[2] -= tmp;
    freq[3] -= tmp;

    for (int i = 2; i < 10; i++)
        if (freq[i] > 0)
            std::cout << i << "";
    return 0;
}