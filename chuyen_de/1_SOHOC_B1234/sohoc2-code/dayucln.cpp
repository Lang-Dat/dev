/**
 *	author: Lăng Trọng Đạt
 *	create: 09-12-2022 32:59:18
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./dayucln.INP", "r", stdin);
    freopen("./dayucln.OUT", "w", stdout);
    #endif

    int64_t t, n, tmp, prev;
    std::cin >> t;
    while (std::cin >> n >> prev) {
        std::cout << prev << " ";
        for (int i = 1; i < n; i++) {
            std::cin >> tmp;
            std::cout <<tmp*prev /  __gcd(tmp, prev) << " ";
            prev = tmp;
        }
        std::cout << tmp << "\n";
    }

    return 0;
}