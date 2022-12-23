/**
 *	author: Lăng Trọng Đạt
 *	create: 25-11-2022 08:16:19
**/
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

static const int LIM = 3*1e5 + 5;
uint64_t a[LIM], b[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    int64_t total = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        total += a[i];
    }
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
        total -= b[i];
    }
    
    if (total != 0) {
        cout << -1;
        return 0;
    }
    int ans = 0;
    int i = 0, j = 0;
    while (i < n) {
        ans++;
        uint64_t curr_a = a[i++], curr_b = b[j++];
        while (curr_a != curr_b) {
            if (curr_a > curr_b) curr_b += b[j++];
            else curr_a += a[i++];
        }
    }
    std::cout << ans<< "";
    return 0;
}