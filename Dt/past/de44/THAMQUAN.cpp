#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

#define ull unsigned long long

struct Value {
    int val = 0, index = 0;
};
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./THAMQUAN.INP", "r", stdin);
    // freopen("./test/THAMQUAN/test01/THAMQUAN.INP", "r", stdin);
    freopen("./THAMQUAN.OUT", "w", stdout);

    ull n, m, tmp, luong_xang = 0;
    std::cin >> n >> m;
    Value distance[n], xe[m];
    int ans[n];
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        distance[i].val = tmp;
        distance[i].index = i;
    }
    for (int i = 0; i < m; i++) {
        std::cin >> tmp;
        xe[i].val = tmp;
        xe[i].index = i + 1;
    }
    std::sort(distance, distance + n, [](Value &a, Value&b) -> bool {
        return a.val > b.val;
    });
    std::sort(xe, xe + m, [](Value &a, Value&b) -> bool {
        return a.val < b.val;
    });

    for (int i = 0; i < n; i++) {
        ans[distance[i].index] = xe[i].index;
        luong_xang += (ull)distance[i].val*xe[i].val;
    }
    std::cout << luong_xang << "\n";
    // for (int i : ans)
    //     std::cout << i << "\n";
    return 0;
}