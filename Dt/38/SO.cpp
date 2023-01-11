/**
 *	author: Lăng Trọng Đạt
 *	create: 28-12-2022 27:37:19
**/
#include <iostream>
#include <algorithm>
using namespace std;

int reverse(int n) {
    int sum = 0;
    while (n > 0) {
        sum = sum * 10 + n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./SO.INP", "r", stdin);
    freopen("./SO.OUT", "w", stdout);
    #endif

    int64_t n;
    std::cin >> n;
    if (n == 1) {
        std::cout << 1 << "";
        return 0;
    }
    int prev = 3;

    int ans[] = {
        8, 10, 3, 5, 7, 9, 11, 13, 33, 35, 55, 57, 77, 79, 99, 101, 103, 303, 305, 505, 507, 707, 709, 909, 911, 121, 123, 323, 325, 525, 527, 727, 729, 929, 931, 141, 143, 343, 345, 545, 547, 747, 749, 949, 951, 161, 163, 363, 365, 565, 567, 767, 769, 969, 971, 181, 183, 383, 385, 585, 587, 787, 789, 989, 991, 201, 104, 403, 306, 605, 508, 807, 710, 19, 93, 41, 16, 63, 38, 85, 60, 8, 10
    };
    // n -= 1;
    n %= 81;
    // n += 2;
    // db(n);
    std::cout << ans[n] << "";
    return 0;
}