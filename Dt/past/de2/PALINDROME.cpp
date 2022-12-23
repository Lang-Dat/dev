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
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./PALINDROME.INP", "r", stdin);
    freopen("./PALINDROME.OUT", "w", stdout);

    long long R, L;
    std::cin >> R >> L;
    std::cout << calc(L) - calc(R - 1);
    return 0;
}