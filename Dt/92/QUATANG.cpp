/**
 *	author: Lang Dat
 *	create: 07-11-2022 07:56:14
**/
#include <iostream>
#include <algorithm>
using namespace std;

#define ull unsigned long long
const int LIM = 1e5 + 5;
unsigned int nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./QUATANG.INP", "r", stdin);
    freopen("./QUATANG.OUT", "w", stdout);
    #endif

    unsigned int n, best = 0, x;
    std::cin >> n >> x;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    sort(nums, nums + n);
    for (int i = 0; i < n; i++) {
        int ind = upper_bound(nums + i + 1, nums + n, x - nums[i] + 1) - nums; 
        if (nums[ind-1] + nums[i] < x) {
            best = max(best, nums[i] + nums[ind -1]);
        }
    }
    std::cout << best << "";
    return 0;
}