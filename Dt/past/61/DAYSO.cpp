/**
 *	author: Lang Dat
 *	create: 18-10-2022 19:17:14
**/
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
const int LIM = 1e5 + 5;
ll nums[LIM], L, R;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./DAYSO.INP", "r", stdin);
    freopen("./DAYSO.OUT", "w", stdout);

    int n, count = 0;
    std::cin >> n >> L >> R;
    for (int i = 1; i <= n; i++) {
        std::cin >> nums[i];
        nums[i] += nums[i-1];
    }
    
    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            if (std::abs(nums[r] - nums[l-1]) >= L &&
                std::abs(nums[r] - nums[l-1]) <= R) {
                    count++;
                }
        }  
    }
    std::cout << count;
    return 0;
}