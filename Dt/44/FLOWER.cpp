/**
 *	author: Lăng Trọng Đạt
 *	create: 03-01-2023 31:29:19
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e6 + 5;
static int h[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./FLOWER.INP", "r", stdin);
    freopen("./FLOWER.OUT", "w", stdout);
    #endif

    int n, m, tmp;
    std::cin >> n >> m;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> h[i];
    }
    
    sort(h, h + n);

    while (std::cin >> tmp) {
        std::cout << n - (lower_bound(h, h + n, tmp) - h) << " ";
    }
    return 0;
}