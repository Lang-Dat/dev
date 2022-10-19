/**
 *	author: Lang Dat
 *	create: 18-10-2022 04:47:19
**/
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

const int LIM = 2 * 1e5 + 5;
ll n, x, y, z, best = INT32_MIN;
ll nums[LIM], max_L[LIM], max_R[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./TichBaSo.INP", "r", stdin);
    freopen("./TichBaSo.OUT", "w", stdout);

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    std::cin >> x >> y >> z;

    max_L[0] = nums[0] * x;
    max_R[n-1] = nums[n-1] * z;   
    for (int l = 1, r = n - 2; l < n; l++, r--) {
        max_L[l] = max(nums[l]*x, max_L[l - 1]);
        max_R[r] = max(nums[r]*z, max_R[r + 1]);
    }
    for (int mid = 1; mid < n - 1; mid++) {
        best = max(best, max_R[mid+1] + max_L[mid-1] + y * nums[mid]);
    }
    std::cout << best;
    return 0;
}