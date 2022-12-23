#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>

long long soUoc(long long n) {
    int count = 0;
    for (int i = 1; i <= std::sqrt(n); i++) {
        if (n % i == 0) count += 2;
        if (i * i == n) count--;
    }
    return count;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./CHIAQUA.INP", "r", stdin);
    freopen("./CHIAQUA.OUT", "w", stdout);

    long long n;
    std::cin >> n;
    std::cout << soUoc(n);
    return 0;
}