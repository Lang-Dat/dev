/**
 *	author: Lăng Trọng Đạt
 *	create: 20-12-2022 05:40:17
**/
#include <iostream>
#include <algorithm>
using namespace std;

#define FOR for (int i = 0; i < n; i++)
static const int LIM = 1e3 + 3;
static int a[LIM], b[LIM], c[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./TRIANGLE.OUT", "w", stdout);
    freopen("./TRIANGLE.INP", "r", stdin);
    #endif

    int n;
    std::cin >> n;
    //int nums[n];
    FOR std::cin >> a[i];
    FOR std::cin >> b[i];
    FOR std::cin >> c[i];
    
    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);
    int count = 0;
    FOR
        for (int j = 0; j < n; j++) {
            int upper = lower_bound(c, c + n, a[i] + b[j]) - c,
                lower = upper_bound(c, c + n, std::abs(a[i] - b[j])) - c;
            count += upper - lower;
            // db(count, a[i], b[j], c[upper], c[lower]);
        }

    std::cout << count << "";
    return 0;
}