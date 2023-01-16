/**
 *	author : Lăng Trọng Đạt
 *	creater: 15-01-2023 08:18:40
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e5 + 5;
static int a[LIM], b[LIM], c[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./SpecSort.INP", "r", stdin);
    freopen("./SpecSort.OUT", "w", stdout);
    #endif

    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 0; i < n; i++) std::cin >> b[i];
    for (int i = 0; i < n; i++) std::cin >> c[i];

    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);

    int ans = 0;
    for (int i = 0, j = -1, z = -1; i < n and j < n and z < n; i++) {
        j = upper_bound(b + j + 1, b + n, a[i]) - b;
        if (j != n) {
            z = upper_bound(c + z + 1, c + n, b[j]) - c;
            if (z != n) {
                ans++;
            }
        }
    }

    std::cout << ans << "";
    return 0;
}