// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
#include <iostream>
#include <vector>
#include <algorithm>

bool compare(int &a, int &b) {
    if (__builtin_popcount(a) > __builtin_popcount(b)) return true;
    if (__builtin_popcount(a) < __builtin_popcount(b)) return false;
    return a > b;
}
std::vector<int> sortByBits(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end(), compare);
    return arr;
}

int main()
{
    std::vector<int> nums = {1, 5, 6};
    // int n;
    // std::cin >> n;
    // for (int i = 0; i < n; i++) std::cin >> nums[i];
    auto ans = sortByBits(nums);
    logl(ans);
}