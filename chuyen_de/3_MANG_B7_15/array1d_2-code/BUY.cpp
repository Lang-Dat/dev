/**
 *	author: Lăng Trọng Đạt
 *	create: 21-12-2022 56:05:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

struct Shop {
    int so_luong, cost, count = 0, index = INT32_MAX;
};
static const int LIM = 1e4 + 5;
static Shop shops[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BUY.INP", "r", stdin);
    freopen("./BUY.OUT", "w", stdout);
    #endif

    int n, m;
    std::cin >> m >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> shops[i].so_luong >> shops[i].cost;
        shops[i].index = i;
    }
    
    sort(shops, shops + n, [](Shop &a, Shop &b) -> bool {
        if (a.cost == b.cost)
            return a.so_luong > b.so_luong;
        return a.cost < b.cost;
    });

    int sum = 0;
    for (int i = 0; i < n and m > 0; i++) {
        int cnt = min(m, shops[i].so_luong);
        sum += cnt*shops[i].cost;
        m -= cnt;
        shops[i].count = cnt;
    }
    sort(shops, shops + n, [](Shop &a, Shop &b) -> bool {
        return a.index < b.index;
    });
    std::cout << sum << "\n";
    for (int i = 0; i < n; i++) {
        std::cout << shops[i].count << "\n";
    }
    return 0;
}