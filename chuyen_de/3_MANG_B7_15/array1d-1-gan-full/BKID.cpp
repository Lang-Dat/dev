/**
 *	author: Lăng Trọng Đạt
 *	create: 16-12-2022 30:00:20
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BKID.INP", "r", stdin);
    freopen("./BKID.OUT", "w", stdout);
    #endif

    int n, curr, min = INT32_MAX, min_ind = 1, index = 2;
    std::cin >> n >> min;

    while (std::cin >> curr) {
        if (min < curr) {
            std::cout << index << "\n";
        } else {
            std::cout << min_ind << "\n";
            min = curr;
            min_ind = index;
        }
        index++;
    }

    return 0;
}