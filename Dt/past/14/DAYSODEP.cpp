/**
 *	author: Lăng Trọng Đạt
 *	create: 05-12-2022 32:13:20
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static const int LIM_VALUE = 1e6,
                 LIM = 5 * 1e4 + 5; // sub 3
int nums[LIM], divisors[LIM_VALUE]; // divisors[i]: number of divisor of i
int dp[LIM]; // LIS

void sieveDivisor() {
    // Time complexity: O(nLog2(n)) (n is LIM_VALUE)
    for (int i = 1; i < LIM_VALUE; i++)
        for (int j = i; j < LIM_VALUE; j += i)
            divisors[j]++;
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./DAYSODEP.INP", "r", stdin);
    freopen("./DAYSODEP.OUT", "w", stdout);
    #endif

    sieveDivisor();   

    int n, tmp;
    std::cin >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        nums[i] = divisors[tmp];
    }

    int best = 0;
    for (int i = 0; i < n; i++) { // O(n^2)
        for (int j = 0; j < i; j++)
            if (nums[i] > nums[j] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        best = max(best, dp[i]);
    }
    
    std::cout << best + 1 << "";
    return 0;
}