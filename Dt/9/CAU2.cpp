/**
 *	author: Lăng Trọng Đạt
 *	create: 01-12-2022 07:30:07
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./CAU2.INP", "r", stdin);
    freopen("./CAU2.OUT", "w", stdout);
    #endif

    int t;
    int64_t ucln, n, tmp;
    std::cin >> t;
    while (std::cin >> n >> ucln) {
        for (int i = 1; i < n; i++) {
            std::cin >> tmp;
            ucln = __gcd(ucln, tmp);
        }
        int64_t count = 0;
        for (int i = 1; i * i <= ucln; i++) {
            if (ucln % i == 0) {
                count++;
                if (i * i != ucln) count++;
            }
        }
        std::cout << count << "\n";
    }

    return 0;
}