/**
 *	author: Lăng Trọng Đạt
 *	create: 23-12-2022 42:14:14
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./ORIGINAL.INP", "r", stdin);
    freopen("./ORIGINAL_trau.OUT", "w", stdout);
    #endif

    int n, k;
    std::cin >> n >> k;

    while (k--) {
        int last = n % 10;
        n /= 10;
        n += 100*last;
    }

    std::cout << n << "";

    return 0;
}