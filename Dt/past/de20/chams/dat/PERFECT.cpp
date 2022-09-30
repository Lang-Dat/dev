#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>

#define ull unsigned long long

bool tongUoc(ull n) {
    ull sum = 1;
    for (ull i = 2; i <= std::sqrt(n); i++) {
        if (n % i == 0 && i * i != n) sum = sum + i + n / i;
        else if (n % i == 0 && i * i == n) sum += i;
    }
    // log(sum, n)
    return (sum == n && n != 1);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./PERFECT.INP", "r", stdin);
    freopen("./PERFECT.OUT", "w", stdout);

    ull tmp, n, count = 0;
    std::cin >> n;
    while (std::cin >> tmp)
        count += tongUoc(tmp);

    std::cout << count << " ";

    return 0;
}