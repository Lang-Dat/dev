#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>

const int LIM = 1e4 + 4;
int nums[LIM];
int n;

int maxSumWOCos() {
    int sum[n]; // ans up to i
    if (n == 1)
        sum[0] = nums[0];
    if (n >= 2)
        sum[1] = nums[0]+nums[1];
    if (n > 2)
        sum[2] = std::max(sum[1], std::max(nums[1]+nums[2], nums[0]+nums[1]));

    // Process rest of the elements
    // We have three cases
    // 1) Exclude arr[i], i.e., sum[i] = sum[i-1]
    // 2) Exclude arr[i-1], i.e., sum[i] = sum[i-2] + arr[i]
    // 3) Exclude arr[i-2], i.e., sum[i-3] + arr[i] + arr[i-1]
    for (int i = 3; i < n; i++) {
        sum[i] = std::max(sum[i-1], 
                 std::max(sum[i-2]+nums[i], sum[i-3] + nums[i] + nums[i-1]));
    }
    return sum[n-1];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // freopen("./BOTTLES.INP", "r", stdin);
    // freopen("./BOTTLES.OUT", "w", stdout);

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    std::cout << maxSumWOCos();
    return 0;
}