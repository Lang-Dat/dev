/**
 *	author: Lăng Trọng Đạt
 *	create: 09-12-2022 16:53:19
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

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./dprime3.INP", "r", stdin);
    freopen("./dprime3.OUT", "w", stdout);
    #endif

    int n;
    std::cin >> n;
    bool isPrinted = false;

    for (int i = 3; i <= sqrt(n - 4); i += 2) {
        if (isPrime_(i)) {
            int z = 4 + i * i;
            if (isPrime_(z)) {
                isPrinted = true;
                std::cout << 2 << " " << i << " " << z << "\n";
            }
        }
    }

    if (!isPrinted)
        std::cout << -1 << "";

    return 0;
}