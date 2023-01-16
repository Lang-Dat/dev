/**
 *	author: Lăng Trọng Đạt
 *	create: 29-12-2022 36:21:20
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./candies.INP", "r", stdin);
    freopen("./candies.OUT", "w", stdout);
    #endif

    int count = 0, n, sum = 0, curr;
    std::cin >> n;
    while (std::cin >> curr)
        if (curr > 0 and curr % 3 == 0) {
            count++;
            sum += curr - 3;
        }

    std::cout << count << "\n" << sum / 3;
    return 0;
}