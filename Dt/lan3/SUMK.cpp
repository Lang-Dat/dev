/**
 *	author: Lang Dat
 *	create: 08-11-2022 53:57:15
**/
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

long long n, target;
int ans = 0;
std::unordered_map<int, int> freq = {{0, 1}};
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./SUMK.INP", "r", stdin);
    freopen("./SUMK.OUT", "w", stdout);
    #endif

    std::cin >> n >> target;    
    int nums[n + 1];
    nums[0] = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> nums[i];
        if (nums[i] == target) ans--;
        nums[i] += nums[i-1];
        if (freq.count(nums[i] - target)) {
            ans += freq[nums[i] - target];
        }
        freq[nums[i]]++;
    }
    std::cout << ans << "";
    return 0;
}