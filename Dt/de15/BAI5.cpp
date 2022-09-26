#pragma GCC optimize("O2")
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>

bool isPrime(int n) {
    if (n < 4) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i <= std::sqrt(n); i += 6) 
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
int reverse(int n) {
    int rev = 0;
    while (n > 0)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI5.INP", "r", stdin);
    freopen("./BAI5.OUT", "w", stdout);

    int p, q;
    std::cin >> p >> q;
    std::vector<int> ans;
    ans.reserve(q - p);
    for (int i = p; i <= q; i++)
        if (isPrime(reverse(i)))
            ans.push_back(i);
    std::sort(ans.begin(), ans.end());

    for (int i : ans)
        std::cout << i << "\n";
    
    return 0;
}