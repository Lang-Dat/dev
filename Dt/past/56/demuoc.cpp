/**
 *	author : Lăng Trọng Đạt
 *	creater: 14-01-2023 19:28:04
**/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

inline bool le_uoc(int64_t n) {
    return (int64_t)(sqrt(n))*(int64_t)(sqrt(n)) == n;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./demuoc.INP", "r", stdin);
    freopen("./demuoc.OUT", "w", stdout);
    #endif

    int64_t n, tmp, count = 0;
    std::cin >> n;
    while (std::cin >> tmp) {
        count += le_uoc(tmp);
    }
    std::cout << n - count << "\n" << count;
    return 0;
}