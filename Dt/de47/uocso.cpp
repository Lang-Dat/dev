#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>

#define ull unsigned long long

void decresingN(ull &n, ull i, ull &count) {
    int tmp = 0;
    while (n % i == 0) {
        n /= i;
        tmp++;
    }
    count *= (tmp + 1);
}

ull soUoc(ull n, ull count = 1) {
    decresingN(n, 2, count);
    decresingN(n, 3, count);
    for (ull i = 5; i * i <= n; i += 6) {
        decresingN(n, i, count);
        decresingN(n, i+2, count);
    }
    if (n > 1) count *= 2;
    return count;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./uocso.INP", "r", stdin);
    freopen("./uocso.OUT", "w", stdout);

    ull t, a, b;
    std::cin >> t;
    while (std::cin >> a >> b) {
        std::cout << soUoc((ull)a*b) << "\n";
    }
    return 0;
}