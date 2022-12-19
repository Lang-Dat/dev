/**
 *	author: Lăng Trọng Đạt
 *	create: 18-12-2022 11:19:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

int calc(int start, int end) {
    int res = 0;
    if (start >= 12) {
        if (end - start <= 4) res = (end - start) * 10;
        else res = 4*10 + (end-start-4)*10/2;
    } else { 
        if (end - start <= 4) res = (end - start) * 6;
        else res = 4*6 + (end-start-4)*6/2;
    }
    return res;
} 

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./khuvuichoi.OUT", "w", stdout);
    freopen("./khuvuichoi.INP", "r", stdin);
    #endif

    int start, end, ans = 0;
    bool isSale = false;

    std::cin >> start >> end;

    if (start < 12 and end > 12) {
        ans = calc(start, 12) + calc(12, end);
    } else {
        ans = calc(start, end);
    }

    std::cout << ans << "";
    return 0;
}