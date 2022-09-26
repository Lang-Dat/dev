#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>
#include <algorithm>

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI2.INP", "r", stdin);
    freopen("./BAI2.OUT", "w", stdout);

    ull N, M;
    std::cin >> N >> M;
    ull last = (std::pow(10, N) + 0.1f) - 1, first = (int)(std::pow(10, N-1) + 0.1f) - 1;
    std::cout << last / M - first / M << " ";
    return 0;
}