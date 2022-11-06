/**
 *	author: Lang Dat
 *	create: 06-11-2022 35:23:19
**/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./GAME.INP", "r", stdin);
    freopen("./GAME.OUT", "w", stdout);
    #endif

    int n;
    std::cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    sort(nums, nums + n);
    std::cout << nums[n-1] + nums[n-2] + nums[n-3] << "";
    return 0;
}