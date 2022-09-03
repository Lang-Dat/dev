#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

// Approach 1:
// Complexity Analysis

// Given N as the length of nums and kk as the maximum element in nums,

// Time complexity: O(N + k)

// To populate points, we need to iterate through nums once, which costs O(N)O(N) time. Then, we call maxPoints(maxNumber). This call will repeatedly call maxPoints until we get down to our base cases. Because of cache, already solved sub-problems will only cost O(1) time. Since maxNumber = k, we will solve k unique sub-problems so, this recursion will cost O(k) time. Our final time complexity is O(N + k).

// Space complexity: O(N + k)

// The extra space we use is the hash table points, the recursion call stack needed to find maxPoints(maxNumber), and the hash table cache.

// The size of points is equal to the number of unique elements in nums. In the worst case, where every element in nums is unique, this will take O(N)O(N) space. The recursion call stack will also grow up to size k, since we start our recursion at maxNumber, and we don't start returning values until our base cases at 0 and 1. Lastly, cache will store the answer for all states, from 2 to maxNumber, which means it also grows up to k size. Our final space complexity is O(N+2⋅k) = O(N + k).
std::map<int, int> catchPoints;
std::map<int, int> points;

int max(int a, int b)
{return a > b ? a : b;}

int maxPoints(int num)
{
    if (num == 1) return points[1];
    if (num == 0) return 0;
    if (catchPoints.count(num)) return catchPoints[num];
    
    int maxPoint = max(maxPoints(num - 1), maxPoints(num - 2) + points[num]);
    catchPoints[num] = maxPoint;
    return maxPoint;
}

int deleteAndEarn(std::vector<int>& nums) {
        int max = 0;        
        for (int num : nums)
        {
            if (num > max) max = num;
            points[num] += num;
        }
    
    return maxPoints(max);
}  

int main()
{
    std::vector<int> nums = {3, 3, 3, 4, 1, 6, 4, 2, 4, 2};
    // int n;
    // std::cin >> n;
    // std::vector<int> nums(n);
    // for (int i = 0; i < n; i++) std::cin >> nums[i];
    
    std::cout << deleteAndEarn(nums);
}