#pragma GCC optimize("O2")
#include <math.h>
#include <iostream>

bool isPrime(int n) {
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i <= std::sqrt(n); i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}
bool isPalindrome(int n) {
    int rev = 0, tmp = n;
    while (tmp > 0)
    {
        rev = rev*10 + tmp%10;
        tmp /= 10;
    }
    return rev == n;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./NTDX.INP", "r", stdin);
    freopen("./NTDX.OUT", "w", stdout);

    int l, r, count = 0;
    std::cin >> l >> r;
    for (int i = l; i <= r; i++)
        if (isPalindrome(i) && isPrime(i))
            count++;
    std::cout << count;

    return 0;
}