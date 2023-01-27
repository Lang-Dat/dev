/**
 *	author : Lăng Trọng Đạt
 *	creater: 26-01-2023 08:33:41
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./laptrinh.INP", "r", stdin);
    freopen("./laptrinh.OUT", "w", stdout);
    #endif

    int min_time = INT32_MAX, count = 0, n, tmp;
    std::cin >> n;
    while (std::cin >> tmp) {
        if (tmp < min_time) {
            min_time = tmp;
            count = 1;
        } else if (tmp == min_time) {
            count++;
        }
    }

    std::cout << min_time << "\n" << count;
    return 0;
}