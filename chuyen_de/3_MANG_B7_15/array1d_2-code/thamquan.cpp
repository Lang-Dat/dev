/**
 *	author: Lăng Trọng Đạt
 *	create: 21-12-2022 34:39:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 3 * 1e4 + 5;
static int khoang_cach[LIM], tieu_thu[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./thamquan.INP", "r", stdin);
    freopen("./thamquan.OUT", "w", stdout);
    #endif

    int n, m;
    std::cin >> n >> m;
    //int khoang_cach[n];
    for (int i = 0; i < n; i++) {
        std::cin >> khoang_cach[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> tieu_thu[i];
    }
    
    sort(khoang_cach, khoang_cach + n, greater<int>());
    sort(tieu_thu, tieu_thu + m);
    int64_t ans = 0;

    for (int i = 0; i < n; i++) {
        ans += khoang_cach[i] * tieu_thu[i];
    }
    std::cout << ans << "";
    return 0;
}