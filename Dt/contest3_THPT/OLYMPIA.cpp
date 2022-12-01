/**
 *	author: Lăng Trọng Đạt
 *	create: 27-11-2022 26:50:08
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static const int LIM = 1e6 + 5;
int need[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./OLYMPIA.INP", "r", stdin);
    freopen("./OLYMPIA.OUT", "w", stdout);
    #endif

    int n, c, k, ky_nang, iq;
    std::cin >> n >> c >> k;
    for (int i = 0; i < n; i++) {
        std::cin >> ky_nang >> iq;
        int tmp = k - ky_nang;
        if (tmp <= 0) need[i] = 0;
        else if (iq == 0) need[i] = -1;
        else {
            need[i] = tmp / iq + (tmp % iq != 0);
        }
    }
    sort(need, need + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (need[i] == -1) continue;
        c -= need[i];
        if (c >= 0) ans++;
    }
    std::cout << ans << "";
    return 0;
}