/**
 *	author: Lăng Trọng Đạt
 *	create: 21-12-2022 56:32:19
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./FLOWERS.INP", "r", stdin);
    freopen("./FLOWERS.OUT", "w", stdout);
    #endif

    int n, prev, curr, count = 1, best = 0, length = 1;
    std::cin >> n >> prev;
    while (std::cin >> curr) {
        if (curr == prev) count++;
        else count = 1;
        if (count >= 3) {
            length = 1;
        }
        length++;
        best = max(best, length);
        prev = curr;
    }

    std::cout << best << "";

    return 0;
}