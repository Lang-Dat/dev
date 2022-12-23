/**
 *	author: Lăng Trọng Đạt
 *	create: 08-12-2022 51:36:15
**/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime_(uint64_t n) {
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (uint64_t i = 5; i <= std::sqrt(n); i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}
inline bool isPerfectSQ(uint64_t n) {
    return (uint64_t)std::sqrt(n) * (uint64_t)std::sqrt(n) == n;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./TNUM.INP", "r", stdin);
    freopen("./TNUM.OUT", "w", stdout);
    #endif

    int64_t n, tmp;
    std::cin >> n;
    while (std::cin >> tmp) {
        cout <<  ((isPerfectSQ(tmp) && isPrime_(sqrt(tmp))) ? "YES" : "NO") << "\n";
    }
    return 0;
}