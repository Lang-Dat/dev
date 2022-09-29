#pragma GCC optimize("O2")
#include <iostream>
#include <bitset>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./HV.INP", "r", stdin);
    freopen("./HV2.OUT", "w", stdout);

    std::size_t n;
    std::cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = n - 1; j >= 0; j--)
            if ((1 << j) & i) std::cout << 1;
            else std::cout << 0;
        std::cout << "\n";
    }

    return 0;
}