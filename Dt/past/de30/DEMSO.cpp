#pragma GCC optimize("O2")
#include <iostream>

// count palindrome number from 1 -> n
long long calc(long long n) {
    if (n < 10) return n;
    long long sum = n / 10 + 9, last = n % 10 ;
    while (n > 9) n /= 10;
    if (n > last) sum--;
    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DEMSO.INP", "r", stdin);
    freopen("./DEMSO.OUT", "w", stdout);

    long long l, r;
    std::cin >> l >> r;
    std::cout << calc(r) - calc(l-1) << "";

    return 0;
}