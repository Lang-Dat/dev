/**
 *	author: Lăng Trọng Đạt
 *	create: 08-12-2022 42:23:08
**/
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

bool isPrime_(uint64_t n) {
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (uint64_t i = 5; i <= std::sqrt(n); i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}

uint64_t reverse(uint64_t n) {
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10; 
        n /= 10;
    }
    return rev;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./CPRIME.INP", "r", stdin);
    freopen("./CPRIME.OUT", "w", stdout);
    #endif

    uint64_t n;
    std::cin >> n;    
    cout << (isPrime_(n) and isPrime_(reverse(n)));
    return 0;
}