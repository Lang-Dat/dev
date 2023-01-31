/**
 *	author : Lăng Trọng Đạt
 *	creater: 30-01-2023 14:00:48
**/
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

std::unordered_set<char> so_le = {'1', '3', '5', '7', '9'};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./COUNT.INP", "r", stdin);
    freopen("./COUNT.OUT", "w", stdout);
    #endif

    char tmp;
    int ans = 0;
    while (std::cin >> tmp) {
        ans += so_le.count(tmp);
    }    

    std::cout << ans << "";
    return 0;
}