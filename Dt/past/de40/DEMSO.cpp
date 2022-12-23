#pragma GCC optimize("O2")
#include <iostream>

#define ull unsigned long long
ull L, R;

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

    std::cin >> L >> R;
    std::cout << calc(R) - calc(L-1) ;
    
    return 0;
}