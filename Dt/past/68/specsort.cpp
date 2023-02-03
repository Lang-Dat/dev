/**
 *	author : Lăng Trọng Đạt
 *	creater: 31-01-2023 21:26:06
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e5 + 5;
static int a[LIM], b[LIM], c[LIM];
int n;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./specsort.INP", "r", stdin);
    freopen("./specsort.OUT", "w", stdout);
    #endif

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);
    int64_t ans = -1;

    for (int i = 0, j = -1, z = -1; i < n and j != n and z != n; i++) {
        ans++;
        j = upper_bound(b + j + 1, b + n, a[i]) - b;
        z = upper_bound(c + z + 1, c + n, b[j]) - c;
    }

    std::cout << ans << "";
    return 0;
}