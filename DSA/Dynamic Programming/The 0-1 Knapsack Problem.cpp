#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int knapsack(vector<int>& values, vector<int>& weights, int maxWeightConstraint) {
        // https://backtobackswe.com/platform/content/the-knapsack-problem/code/
        // Time: O(n*m)
        // Space: O(n*m)
        int n = values.size();
        std::vector<std::vector<int>> dp(n + 1, vector<int>(maxWeightConstraint + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= maxWeightConstraint; j++) {
                if (weights[i - 1] <= j) {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j - weights[i-1]] + values[i - 1]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][maxWeightConstraint];
    }
};

int main() {
    vector<int> values = {60, 50, 70, 30}, weights = {5, 3, 4, 2};
    Solution ob;
    std::cout << ob.knapsack(values, weights, 120) << "";
}