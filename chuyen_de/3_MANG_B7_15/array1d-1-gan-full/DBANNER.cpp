/**
 *	author: Lăng Trọng Đạt
 *	create: 17-12-2022 16:11:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e3 + 5;
static int h[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./DBANNER.INP", "r", stdin);
    freopen("./DBANNER.OUT", "w", stdout);
    #endif

    int n;
    std::cin >> n;
    //int h[n];
    for (int i = 0; i < n; i++) {
        std::cin >> h[i];
    }
    
    int best = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i, min_h = h[i]; j < n; j++) {
            min_h = min(min_h, h[j]);
            best = max(best, min_h * (j - i + 1));
        }
    }

    std::cout << best << "";
    return 0;
}