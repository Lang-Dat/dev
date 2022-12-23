#pragma GCC optimize("O2")
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>

// phai dung ull vi voi cac so co 10 chu so thi khi dao nguoc no se bi qua gioi han cua int
#define ull unsigned long long

bool isPrime(ull n) {
    if (n < 4) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ull i = 5; i <= std::sqrt(n); i += 6) 
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
ull reverse(ull n) {
    ull rev = 0;
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

    ull p, q;
    std::cin >> p >> q;
    std::vector<ull> ans;
    ans.reserve(q - p);
    for (ull i = p; i <= q; i++)
        if (isPrime(reverse(i)))
            ans.push_back(i);
    std::sort(ans.begin(), ans.end());
    for (ull i : ans)
        std::cout << i << "\n";
    
    return 0;
}