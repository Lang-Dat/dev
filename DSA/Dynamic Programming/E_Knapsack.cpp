#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    long long knapsack(vector<long long>& values, long long maxWeightConstraint) {
        // https://backtobackswe.com/platform/content/the-knapsack-problem/code/
        // Time: O(n*m)
        // Space: O(n*m)
        int n = values.size();
        std::vector<std::vector<long long>> dp(n + 1, vector<long long>(maxWeightConstraint + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= maxWeightConstraint; j++) {
                if (i <= j) {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j -i] + values[i - 1]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][maxWeightConstraint];
    }
};

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::vector<long long> cost(n);
    
    for (int i = 0; i < n; i++)
        std::cin >> cost[i];
    
    Solution ob;
    std::cout << ob.knapsack(cost, m) << "";
}