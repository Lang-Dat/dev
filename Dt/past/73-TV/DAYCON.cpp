/**
 *	author : Lăng Trọng Đạt
 *	creater: 02-02-2023 10:10:37
**/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DAYCON.INP", "r", stdin);
    freopen("./DAYCON.OUT", "w", stdout);

    int64_t n, best = 0, tmp, curr = 0;

    std::cin >> n;
    while (std::cin >> tmp) {
        curr = max(tmp, curr + tmp);
        best = max(best, curr);
    }

    std::cout << best << "";
    return 0;
}