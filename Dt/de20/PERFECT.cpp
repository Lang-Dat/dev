#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>

#define ull unsigned long long

bool tongUoc(int n) {
    int sum = 0;
    for (int i = 1; i <= std::sqrt(n); i++) {
        if (i * i == n) sum += i;
        else if (n % i == 0) sum += i + n / i;
    }
    sum -= n;
    return sum == n;
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