/**
 *	author: Lăng Trọng Đạt
 *	create: 25-11-2022 11:51:15
**/
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}; // Log2(1e12)

int calc(uint64_t n) {
    //  tính số số không phải là số nguyên tố nhưng có số ước là SNT
    int end = 0;
    int count = 0;
    uint64_t tmp = 1;
    for (;tmp * primes[end] <= n; end++) {
        tmp *= primes[end];

    }
    end--;
    for (int i = 0; i < primes.size() - 1; i++) {
        for (int j = 1; j < primes.size() - 1; j++) {
            if ((uint64_t)(pow(primes[i], primes[j] - 1) + .1) <= n)
                count++;
            else break;
        }
    }

    return count;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI4.INP", "r", stdin);
    freopen("./BAI4.OUT", "w", stdout);
    #endif

    uint64_t l, r;
    std::cin >> l >> r;
    
    cout << calc(r) - calc(l-1);
    return 0;
}