/**
 *	author: Lang Dat
 *	create: 07-11-2022 35:07:15
**/
#include <iostream>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./QUATANG.INP", "r", stdin);
    freopen("./QUATANG_trau.OUT", "w", stdout);
    #endif

    int n, best = 0, x;
    std::cin >> n >> x;
    int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] <= x)
                best = max(best, nums[i] + nums[j]);
        }
    }
    std::cout << best << "";
    return 0;
}