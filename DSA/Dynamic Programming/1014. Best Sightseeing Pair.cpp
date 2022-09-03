// https://leetcode.com/problems/best-sightseeing-pair/
#include <iostream>
#include <vector>


int maxScoreSightseeingPair(std::vector<int>& values) {
    // We can segregate the problem as, to maximise ((v[i]+i) + (v[j]-j))
    int n = values.size();
    int maxDiffRigth = INT32_MIN, maxScore = INT32_MIN;
    for (int i = n - 2; i >= 0; i--)
    {
        if (values[i+1] - i > maxDiffRigth) maxDiffRigth = values[i+1] - i - 1;
        if (maxDiffRigth + values[i] + i > maxScore) maxScore = maxDiffRigth + values[i] + i;
        // log(maxDiffRigth); logl(maxScore);
    }

    return maxScore;
}


int main()
{
    // freopen("big input.txt", "r", stdin);
    int n;
    std::cin >> n;
    std::vector<int> nums(n);

    for (int i = 0; i < nums.size(); i++) std::cin >> nums[i];

    std::cout << (maxScoreSightseeingPair(nums));
}