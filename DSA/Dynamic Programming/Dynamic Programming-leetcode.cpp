#include <iostream>
#include <vector>

#define log(x) std::cout << x << " ";
class Solution
{
public:
    int fibBase(int n)
    {
        // Time: O(1.6^n)
        if (n == 0) return 0;
        if (n <= 2) return 1;
        return fibBase(n - 1) + fibBase(n - 2);
    }
    int tribonacci(const int n) 
    {   // time: O(n);
        if (n < 2) return n;
        if (n == 2) return 1;
        int dp[n+1];
        dp[0] = 0; dp[1] = 1; dp[2] = 1;
        for (int i = 3; i <= n; i++)
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        return dp[n];
    }
    int climbStairs(int n) {
        long long a = 1, b = 1;
        for (long long i = 1; i <= n; i++)
        {
            long long temp = a;
            a = b;
            b = a + temp;
        }
        return a;
    }
    int min(int a, int b) {return a > b ? b : a;}
    int minCostClimbingStairs(std::vector<int>& cost) {
        int n = cost.size();
        int minimumCost[n+1];
        
        minimumCost[n] = 0;
        minimumCost[n-1] = cost[n-1];
        for (int i = n - 2; i >= 0; i--)
        {
            minimumCost[i] = cost[i] + min(minimumCost[i+1], minimumCost[i+2]);
        }
        return min(minimumCost[0], minimumCost[1]);
    }
    
};


int main()
{
    Solution object = Solution();

    std::vector<int> v = {10,15,20};
    std::cout << object.minCostClimbingStairs(v);
}