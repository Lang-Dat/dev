/**
 *	author: Lăng Trọng Đạt
 *	create: 29-12-2022 08:02:20
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./SEQ.INP", "r", stdin);
    freopen("./SEQ.OUT", "w", stdout);
    #endif

    int n, best = 0, x;
    std::cin >> n >> x;
    int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i, curr = 0; j < n; j++) {
            curr += nums[j] * x;
            best = max(best, curr);
        }
    }

    std::cout << best << "";
    return 0;
}